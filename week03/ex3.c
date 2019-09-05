#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} node;

int size_of_list(node *list){
    int size = 0;
    while(list != NULL){
        list = list->next;
        ++size;
    }
    return size;
}

void print_list(node *list){
    printf("Values in list:");
    while (list != NULL){
        printf(" %d",list->value);
        list = list->next;
    }
    printf("\n");
}

void insert_node(node **list, node *new_node, int index){
    if(size_of_list(*list) == 0){
        *list = new_node;
    }
    else if(index == 0){
        new_node->next = *list;
        *list = new_node;
    }
    else if(index >= size_of_list(*list)){
        node *temp = *list;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else{
        node *temp = *list;
        for(int i = 0; i < index - 1; ++i){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int delete_node(node **list, int index){

    if(size_of_list(*list) == 0){
        return;
    }

    if(size_of_list(*list) == 1){
        int value = (*list)->value;
        *list = NULL;
        return value;
    }

    if(index == 0){
        int value = (*list)->value;
        (*list) = (*list)->next;
        return value;
    }

    if(index >= size_of_list(*list) - 1){
        node *temp = *list;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        int value = temp->next->value;
        temp->next = NULL;
        return value;
    }
    
    node *temp = *list;
    for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
    }
    int value = temp->next->value;
    temp->next = temp->next->next;
    return value;
}

int main(){
    node *list = malloc(sizeof(node));
    node *second = malloc(sizeof(node));
    node *third = malloc(sizeof(node));
    node *fourth = malloc(sizeof(node));
    list->value = 1;
    second->value = 2;
    third->value = 3;
    fourth->value = 4;
    print_list(list);
    insert_node(&list, second, 1);
    print_list(list);
    insert_node(&list, third, 1);
    print_list(list);
    insert_node(&list, fourth, 1);
    print_list(list);
    delete_node(&list, 0);
    print_list(list);
    delete_node(&list, 2);
    print_list(list);
    return 0;
}