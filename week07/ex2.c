#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter your number:");
    int size = 0;
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    for(int i = 0; i < size; ++i){
        array[i] = i;
        printf("%d\n", array[i]);
    }
    free(array);
}