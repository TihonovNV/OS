#include <stdio.h>

int main(){ 
    char* buff = malloc(256);
    setvbuf(stdout, buff, _IOLBF, 256);
    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    return 0;
}