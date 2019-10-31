#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main(){ 
    int fdin, fdout;
    char *src, *dst;
    struct stat statbuff;
    fdin = open("./ex4.txt", O_RDONLY);
    fdout = open("./ex4.memcpy.txt", O_RDWR);
    stat(src, &statbuff);
    src = mmap(0, statbuff.st_size, PROT_READ, MAP_SHARED, fdin, 0);
    dst = mmap(0, statbuff.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
    memcpy(dst, src, statbuff.st_size);
    return 0;
}