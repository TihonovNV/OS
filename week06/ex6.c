#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 256
#define true 1

int main(){
    int p[2];
    pipe(p);
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == 0){
        printf("Child1 created\n");
        char* mainId = malloc(MAXLINE);
        read(p[0], mainId, MAXLINE);
        printf("Child2 id: %s\n", mainId);
        int child2;
        sscanf(mainId, "%d", &child2);
        sleep(2);
        kill(child2, SIGSTOP);
        printf("Child2 is killed\n");
        printf("Exiting child 1\n");
        exit(0);
    }
    else {
        pid2 = fork();
        if(pid2 == 0){
            printf("Child2 created\n");
            while(true){
                printf("Child 2\n");
                sleep(1);
            }
        }
        else{
            printf("Main process\n");
            char* childId = malloc(MAXLINE);
            sprintf(childId, "%d", pid2);
            printf("Child2 id: %d\n", pid2);
            write(p[1], childId, MAXLINE);
            printf("Child2 id was sent, waiting\n");
            waitpid(pid2, NULL, WUNTRACED);
            printf("Waiting is over\n");
        }
    }
    return 0;
}