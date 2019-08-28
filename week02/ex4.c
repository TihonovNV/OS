#include <stdio.h>

void swap(int *a, int *b){
    int k = *a;
    *a = *b;
    *b = k;
}

int main(){
    int first, second;
    printf("Type first integer\n");
    scanf("%d", &first);
    printf("Type second integer\n");
    scanf("%d", &second);
    printf("first - %d, second - %d\n", first, second);
    swap(&first, &second);
    printf("first - %d, second - %d\n", first, second);
    return 1;
}