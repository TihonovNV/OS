#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#define MAXLINE 256

char *string1 = "Some string";
char string2[MAXLINE];

int main(){
    pid_t pid;
    int p[2];
    pipe(p);
    pid = fork();
    if(pid == 0){
        read(p[0], string2, MAXLINE);
        printf("%s\n", string2);
    }
    else {
        write(p[1], string1, MAXLINE);
    }
    return 0;
}