#include <unistd.h>
#include <stdio.h>

int main(){
    if((fork()) == 0){
        printf("Hello from parent[PID - %d]\n", getpid());
    }
    else{
        printf("Hello from child[PID - %d]\n", getpid());
    }
}