#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

#define MEGABYTE (1024*1024)

int main(){
    int *mem;
    struct rusage *usage = malloc(sizeof(struct rusage)); 
    int i = 0;
    while(i < 10){
        mem = malloc(10*MEGABYTE);
        memset(mem, 0, 10*MEGABYTE);
        getrusage(RUSAGE_SELF, usage);
        printf("Memory usage is %lu\n", usage->ru_maxrss);
        sleep(1);
        ++i;
    }
    return 0;
}