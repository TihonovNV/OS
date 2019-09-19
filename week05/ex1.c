#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printThread(void *n){
    int *index = (int*) n;
    printf("Hi, I'm thread number %d\n", *index);
}

int main(){
    int numberOfThreads;
    printf("Type number of threads: ");
    scanf("%d", &numberOfThreads);
    for(int i = 1; i <= numberOfThreads; ++i){
        pthread_t thread;
        pthread_create(&thread, NULL, printThread, &i);
        pthread_join(thread, NULL);
    }
    return 1;
}