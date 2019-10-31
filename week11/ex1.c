#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
//#include <io.h>

int main(){
    struct stat file;
    stat("ex1.txt", &file);
    int ex1;
    ex1 = open("/mnt/d/Dev/OS/week11/ex1.txt", O_RDWR);
    char *output = mmap(0, strlen(word), PROT_READ | PROT_WRITE,
    MAP_SHARED, ex1, 0);
    char* word = "This is a nice day";
    memcpy(output, word, strlen(word));
    return 1;
}