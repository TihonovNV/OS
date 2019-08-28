#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Type your string:\n");
    char *string = (char*)malloc(INT_MAX);
    fgets(string, INT_MAX, stdin);
    for(int i = strlen(string) - 2; i >= 0; --i){
        putchar(string[i]);
    }
    putchar('\n');
    free(string);
    return 1;
}