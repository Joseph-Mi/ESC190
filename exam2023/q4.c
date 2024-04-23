#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_val, int i){
    if (my_list->head == NULL || i == 0){
        node *head = malloc(sizeof(node));
        head->data = new_val;
        head->next = my_list->head;
        my_list->head = head;
    }

    node *curr = my_list->head;
    int count = 0;

    while (curr->next != NULL && count < i-2){
        curr = curr->next;
        count++;
    }
    
    node *new = malloc(sizeof(node));
    new->data = new_val;

    new->next = curr->next;
    curr->next = new;
}

int main(){
    node *one = malloc(sizeof(node));
    node *two = malloc(sizeof(node));
    node *four = malloc(sizeof(node));

    one->data = 1;
    two->data = 2;
    four->data = 4;

    one->next = two;
    two->next = four;
    four->next = NULL;

    LL *list = malloc(sizeof(LL));
    list->head = one;

    LL_append(list, 3, 3);

    node *cur = list->head;


    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
