#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    unsigned char randomWord[20];
    int random = open("/dev/random", O_RDONLY);
    read(random, randomWord, sizeof(randomWord));
    int out = open("./ex1.txt", O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);
    write(out, randomWord, sizeof(randomWord));
    return 0;
}