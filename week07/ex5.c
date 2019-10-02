#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char **s = malloc(10*sizeof(char)*sizeof("Hello World"));
char* foo = malloc(sizeof(char)*sizeof("Hello World"));
strcpy(foo, "Hello World");
*s = (char *)malloc(sizeof(char)*sizeof("Hello World"));
strcpy(*s, foo);
printf("s is %s\n", *s);
s[0] = foo;
printf("s[0] is %s\n",s[0]);
return(0);
} 