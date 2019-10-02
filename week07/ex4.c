#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void* ptr, int size){
    if(!ptr){
        return malloc(size);
    }
    else if(size == 0){
        free(ptr);
    }
    else {
        void* temp = malloc(size);
        memcpy(temp, ptr, size);
        free(ptr);
        ptr = temp;
        return ptr;
    }
}

int main(){
    int* arr;
    arr = (int*)my_realloc(arr, 10*(sizeof(int)));
    for(int i = 0; i < 10; ++i){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = (int*)my_realloc(arr, 5*(sizeof(int)));
    for(int i = 0; i < 5; ++i){
        printf("%d ", arr[i]);
    }
    return 0;
}