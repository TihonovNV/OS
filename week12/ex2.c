#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int stdin = open("/dev/stdin", O_RDONLY);
    int stdout = open("/dev/stdout", O_WRONLY);
    int a = 0, *files, size;
    if(!strcmp("-a", argv[1])){
        a = 1;
    }
    if(a){
        files = calloc(argc - 2, sizeof(int));
        size = argc - 2;
    }
    else{
        files = calloc(argc - 1, sizeof(int));
        size = argc - 1;
    }
    if(a){
        for(int i = 0; i < size; ++i){
            files[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_APPEND, S_IWRITE);
        }
    }
    else{
        for(int i = 0; i < size; ++i){
            files[i] = open(argv[i + 1], O_WRONLY | O_CREAT, S_IWRITE);
        }
    }
    char symbol;
    while (read(stdin, &symbol, sizeof(char))) {
        for(int i = 0; i < argc - 1; ++i) {
            write(files[i], &symbol, sizeof(char));
        }
        write(stdout, &symbol, sizeof(char));
    }
    return 0;
}