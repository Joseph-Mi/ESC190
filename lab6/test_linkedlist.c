#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
     node *head;
     int size;
} LL;
*/

int main(){
    node *three = malloc(sizeof(node));
    three->data = 3;
    three->next = NULL;
    node *two = malloc(sizeof(node));
    two->data = 2;
    two->next = three;
    node *one = malloc(sizeof(node));
    one->data = 1;
    one->next = two;

    
    LL *list = malloc(sizeof(LL));
    list->head = one;
    list->size = 3;
    node *cur = list->head;

    LL_append(list, 4);

    // while (cur != NULL){
    // printf("%d ->hi", cur->data);
    // cur = cur->next;
    // }

    delete(list, 2);
    
    while (cur != NULL){
        printf("%d ->", cur->data);
        cur = cur->next;
    }
}
