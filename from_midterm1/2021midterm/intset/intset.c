#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "intset.h"

void intset_create(struct intset **s){    
    *s = (intset *)malloc(sizeof(intset));
    (*s)->head = NULL;
}

void intset_add(struct intset *s, int *elems, int num_elems){
    node *cur = (node *)malloc(sizeof(node));

    if (num_elems == 0){
        s->head = NULL;
        return;
    }

    s->head = cur;

    for (int i = 0; i < num_elems; i++){
        cur->next = malloc(sizeof(node));
        cur->data = *elems;
        cur = cur->next;
    }
    cur->next = NULL;
}

int intset_iselem(struct intset *s, int elem){
    node *search = (node *)malloc(sizeof(node));
    
    s->head = search;
    while (search->next != NULL){
        if (search->data == elem){
            return 1;
        }
        search = search->next;
    }
    return 0;
}

void intset_remove(struct intset *s, int elem){
    node *prev = (node *)malloc(sizeof(node));
    node *cur = (node *)malloc(sizeof(node));

    prev = s->head;

    if (prev->next != NULL){
        cur = prev->next;
    }

    // if (prev->data == elem){
    //     prev->next = s->head
    // }

    while(cur->next != NULL){
        if (cur->data == elem){
            prev->next = cur->next;
        }
        cur = cur->next;
        prev = prev->next;
    }
    if (cur->data == elem){
        cur->data = NULL;
    }

    prev = s->head;
    if (prev->data == elem){
        prev->next = s->head;
    }

}

void intset_union(struct intset *s1, struct intset *s2, struct intset **s3){
    node *point = malloc(sizeof(node));
    intset_create(s3);
    point = s1->head;

    while(point){
        intset_add(*s3, point->data, 1);
        point = point->next;
    }
    point = s2->head;
    while(point){
        intset_add(*s3, point->data, 1);
        point = point->next;
    }
    point = NULL;
    free(point);

}