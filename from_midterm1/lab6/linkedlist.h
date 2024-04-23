#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
     node *head;
     int size;
} LL;

void LL_append(LL *my_list, int new_elem);
int validate_list_length(LL *list, int length);
void delete(LL *list, int index);

#endif