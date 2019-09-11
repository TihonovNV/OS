#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256

int main(){
    char command[MAXLINE];
    while(strcmp("exit", command)){
        system(command);
        scanf("%s", command);
    }
    return 0;
}