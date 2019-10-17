#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define R 128 //Sets first bit to 1

typedef struct page {
    int index;
    unsigned char counter;
} page;

page* pageFrame;

float aging(int size){
    int hits = 0;
    pageFrame = calloc(size, sizeof(page));
    FILE* input = fopen("input.txt", "r");
    int nextPage;
    while(!feof(input)){
        unsigned char smallest = pageFrame[0].counter;
        int indexOfSmallest = 0;
        bool hit = 0;
        fscanf(input, "%d ", &nextPage);
        for(int i = 0; i < size; ++i){
            if(pageFrame[i].index == 0 && pageFrame[i].counter == 0){
                smallest = pageFrame[i].counter;
                indexOfSmallest = i;
            }
            else if(smallest > pageFrame[i].counter){
                smallest = pageFrame[i].counter;
                indexOfSmallest = i;
            }
            pageFrame[i].counter /= 2; 
            if(pageFrame[i].index == nextPage){
                ++hits;
                pageFrame[i].counter += R;
                hit = 1;
            }
        }
        if(!hit){
            pageFrame[indexOfSmallest].index = nextPage;
            pageFrame[indexOfSmallest].counter = R;
        }
    }
    free(pageFrame);
    fclose(input);
    return hits;//(float)(hits)/(1000 - hits);
}

int main(){
    printf("%f\n", aging(10));//0.011122
    printf("%f\n", aging(50));//0.054852
    printf("%f\n", aging(100));//0.101322
    return 1;
}