#include <stdlib.h>

//syntax from C
//functions conditionals lists
//structs pointers
//define, include, and #if, #endif

//linked lists

typedef struct node{
  int data;
  struct node *next; //line 10 before line 19, so it does not yet know of name node 
} node;

//  1      5
//head -> n2

void create_LL(node **p_head, int *data, int size){
  if (size == 0){
    *p_head = NULL;
    return;
  }
  node *cur = (node *)malloc(sizeof(node));
  cur->data = data[0];
  *p_head = cur;
  for (int i = 1; i < size; i++){
    cur->next = (node *)malloc(sizeof(node));
    cur->next->data = data[i];
    cur = cur->next;
  }
  cur->next = NULL;
}

void print_LL(node *head){
  while (head != NULL){
    printf("%d ->", head->data);
    head = head->next;
  }
}

void insert_LL(node **p_head, int ind, int num){
  //inser num at index ind
  node *new = (node *)malloc(sizeof(node));
  if (ind == 0){
    node *new = (node *)malloc(sizeof(node));
    new->next = *p_head;
    *p_head = new;
  } else{
    //go thru the linked list until node i-1
    //insert new node after i - 1
    node *cur = *p_head;
    for (int i = 0; i < ind - 1; i++){
      cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
  }
}
int main(){
  node *head = (node *)malloc(sizeof(node));
  head->data = 1;

  node *n2 = (node *)malloc(sizeof(node));
  n2->data = 5;
  head->next = n2;

  node a;
  a.data = 123;

  //free(&a) would crash
  //free(a) would not compile as it is not a pointer

  node *n10 = (node *)malloc(sizeof(node));
  head->next = n10;
  n10->next = n2;


}