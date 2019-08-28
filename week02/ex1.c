#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(){
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("size of integer: %d, max value: %d\n", (int)sizeof(a), a);
    printf("size of float: %d, max value: %.10e\n", (int)sizeof(b), b);
    printf("size of double: %d, max value: %.10e\n", (int)sizeof(c), c);
    return 1;
}