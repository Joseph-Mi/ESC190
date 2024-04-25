#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next; 
} Node;

typedef struct PQueue{
    Node *head;
} PQueue;

Node *create_node(int data, int priority){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->priority = priority;
    new->next = NULL;
    return new;
}

PQueue *create_priority_queue(){
    PQueue *queue = (PQueue *)malloc(sizeof(PQueue));
    queue->head = NULL;

    return queue;
}

void insert(PQueue *pq, int data, int weight){
    Node *node = create_node(data, weight);
    
    if (pq->head == NULL || node->priority < pq->head->priority){
        node->next = pq->head;
        pq->head = node;
    } else {
        Node *current = pq->head;
        while (current->next != NULL && node->priority > current->next->priority){
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

int extract_min(PQueue *pq){
    if (pq->head == NULL){
        printf("empty queue");
        exit(1);
    }
    Node *free_node = pq->head;
    int val = free_node->data;
    pq->head = pq->head->next;
    
    free(free_node);
    return val;
}

int main(){
    PQueue *pq = create_priority_queue();

    // Insert elements into the priority queue
    insert(pq, 5, 2);
    insert(pq, 7, 1);
    insert(pq, 3, 3);

    // Extract and print elements with the highest priority
    while (pq->head != NULL){
        printf("%d ", extract_min(pq));
    }

    return 0;
}