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

void LL_append(LL *my_list, int new_elem)
{
    //next linked after last is NULL
    node *last = (node *)malloc(sizeof(node));
    last->data = new_elem;
    last->next = NULL;

    if (my_list->size == 0){
        my_list->head = last;
        my_list->size++;
        return;
    }
    
    node *cur = (node *)malloc(sizeof(node));
    cur = my_list->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    // for (int i = 0; i < (my_list->size)-1; i++){
    //     // cur->next = (node *)malloc(sizeof(node));
    //     cur = cur->next;
    // }
    cur->next = last;
    my_list->size++;
}

int validate_list_length(LL *list, int length){
    int count = 0;
    node *cur = (node *)malloc(sizeof(node));
    cur = list->head;
    while (cur != NULL) {
        cur = cur->next;
        count++;
    }
    return (count == length);
}

void delete(LL *list, int index){
    node *cur = (node *)malloc(sizeof(node));
    node *del = (node *)malloc(sizeof(node));

    if (index < 0 || index >= list->size){
        printf("break");
        return;
    }

    if (index == 0){
        list->head = (list->head)->next;
        list->size--;
        return;
    }

    cur = NULL;
    del = list->head;
    for (int i = 0; i < index - 1; i++){
        cur = del;
        del = del->next;
    }
    cur->next = del->next;
    list->size--;
    free(del);
}
