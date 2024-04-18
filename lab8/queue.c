#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
     node *head;
     int size;
} LL;

void create_LL(node **mylist, int *data, int size){
  if (size == 0){
    *mylist = NULL;
    return;
  }

  node *cur = (node *)malloc(sizeof(node));
  cur->data = data[0];
  *mylist = cur;
  for (int i = 1; i < size; i++){
    cur->next = (node *)malloc(sizeof(node));
    cur->next->data = data[i];
    cur = cur->next;
  }
  cur->next = *mylist;
}

void print_LL(node *head, int size){
	int i = 0;
	while (i < size){
    printf("%d ->", head->data);
    head = head->next;
		i++;
  }
}

// void LL_append(LL *my_list, int new_elem)
// {
//     //next linked after last is NULL
//     node *last = (node *)malloc(sizeof(node));
//     last->data = new_elem;
//     last->next = NULL;

//     if (my_list->size == 0){
//         my_list->head = last;
//         my_list->size++;
//         return;
//     }
    
//     node *cur = (node *)malloc(sizeof(node));
//     cur = my_list->head;
//     while (cur->next != NULL) {
//         cur = cur->next;
//     }
//     // for (int i = 0; i < (my_list->size)-1; i++){
//     //     // cur->next = (node *)malloc(sizeof(node));
//     //     cur = cur->next;
//     // }
//     cur->next = last;
//     my_list->size++;
// }

int main(){
    node *mylist = NULL;

    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int size  = 7;
    // int size = sizeof(data) / sizeof(data[0]);

    create_LL(&mylist, data, size);
    printf("Original Linked List: ");
    print_LL(mylist, size);
		printf("\n");

    return 0;
}