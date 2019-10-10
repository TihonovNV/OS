#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEGABYTE (1024*1024)

int main(){
    int *mem;
    int i = 0;
    while(i < 10){
        mem = malloc(10*MEGABYTE);
        memset(mem, 0, 10*MEGABYTE);
        sleep(1);
        ++i;
    }
    return 0;
}