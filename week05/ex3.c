#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TRUE 1

int buffer = 0;

void waitToProduce(){
    while(buffer == 10)
        sleep(1);
}

void waitToConsume(){
    while(buffer == 0)
        sleep(1);
}

void *produce(){
    while(TRUE){
        if(buffer == 10)
            waitToProduce();
        ++buffer;
    }
}

void *consume(){
    while(TRUE){
        if(buffer == 0)
            waitToConsume();
        --buffer;
    }
}

int main(){
    pthread_t producer;
    pthread_t consumer;
    pthread_create(&producer, NULL, produce, 0);
    pthread_create(&consumer, NULL, consume, 0);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
}