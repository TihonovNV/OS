#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int size;
    sscanf(argv[1], "%d", &size);
    char *string = (char*)malloc((2*size - 1)*sizeof(char));
    for(int i = 0; i < 2*size - 1; ++i){
        if(i == size)
            string[i] = '*';
        else
            string[i] = ' ';
    }
    int left = size - 1, right = size + 1;
    for(int i = 0; i < size; ++i){
        printf("%s\n", string);
        string[left] = '*';
        --left;
        string[right] = '*';
        ++right;
    }
}