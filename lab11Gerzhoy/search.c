//Q2: In C, using the adjacency-matrix-based graph representation, implement BFS and DFS.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int *neigbours;
    int id;
    bool visited;
    int num_neighbours;
} Node;

typedef struct QueueNode {
    struct Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    struct QueueNode *front, *rear;
} Queue;

Queue *create_queue(Queue *q){
    q = (Queue *)malloc(sizeof(Queue) * );
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *node){
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));

    new_node->data = node;
    new_node->next = NULL;

    if (q->rear == NULL){
        q->rear = new_node;
        q->front = new_node;
        return;
    } 
    
    q->rear->next = new_node;
    q->rear = new_node;
}

void BFS(struct Node* start) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    start->visited = true;

    
}

int main(){
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    Node node6;

    //Perform BFS starting from node1
    print("BFS Traversal:")
    BFS(node1)

    visited = set()
    DFS(node1, visited)
}