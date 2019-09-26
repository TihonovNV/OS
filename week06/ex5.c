#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>

#define TRUE 1

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        while(TRUE){
            sleep(1);
            printf("I'm alive!\n");
        }
    }
    else{
        sleep(10);
        kill(0, SIGTERM);
    }
    return 0;
}