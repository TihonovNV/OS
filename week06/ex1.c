#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 256

char *string1 = "Some string";
char string2[MAXLINE];

int main(){
    int p[2];
    pipe(p);
    write(p[1], string1, MAXLINE);
    read(p[0], string2, MAXLINE);
    printf("%s\n", string2);
    return 0;
}