#include <stdio.h>

void bubble_sort(int* array, int size, int compare(int*, int*), void swap(int*, int*)){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1 - i; ++j){
            if(compare((array + j),  (array + (j + 1))) > 0){
                swap((array + j),  (array + (j + 1)));
            }
        }
    }
}

void swap(int* first, int* second){
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int compare(int *first, int *second){
    return (*first - *second);
}

int main(){
    int array[] = {34,12,67,45,90,16,46,99,10,1};
    printf("Before: ");
    for(int i = 0; i < 10; ++i){
        printf("%d ", array[i]);
    }
    putc('\n', stdout);
    bubble_sort(array, 10, compare, swap);
    printf("After: ");
    for(int i = 0; i < 10; ++i){
        printf("%d ", array[i]);
    }
    putc('\n', stdout);
}