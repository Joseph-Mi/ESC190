#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
typedef struct Node {
    int id;
    struct Node* connections[MAX_NODES]; // Array to store connections
    int num_connections; // Number of connections
    int visited; // Flag to track visited status //could be boolean as well
} Node;

// Function to create a new node
Node* create_node(int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->num_connections = 0;
    new_node->visited = 0;
    return new_node;
}

// Function to add a connection between two nodes
void add_connection(Node *node1, Node* node2) {
    node1->connections[node1->num_connections++] = node2;
    node2->connections[node2->num_connections++] = node1;
}

// Function to perform Breadth-First Search
void BFS(Node* start_node) {
    Node *queue[MAX_NODES]; // Queue for BFS traversal
    int front = 0, rear = 0; // Front and rear pointers for the queue


    // Enqueue the start node
    queue[rear++] = start_node;
    // start_node->visited = 1;

    // Perform BFS traversal
    while (front < rear) {
        Node* current_node = queue[front++];
        printf("%d ", current_node->id); // Print the ID of the current node
        current_node->visited = 1;

        // Enqueue all unvisited connections of the current node
        for (int i = 0; i < current_node->num_connections; i++) {
            Node *next_node = current_node->connections[i];
            if (!next_node->visited) {
                queue[rear++] = next_node;
                // next_node->visited = 1;
            }
        }
    }
}

void DFS(start_node){
    Node *stack[MAX_NODES];
    int top = -1;

    stack[++top] = start_node;

    while (top >= 0){
        Node *current = stack[top--];
        current->visited = 1;
        printf("%d ", current->id);

        for (int i = 0; i < current->num_connections; i++){
            Node *next = current->connections[i];
            if (next->visited == 0){
                stack[++top] = next;
            }
        }
    }
}

int main() {
    // Create nodes
    Node* n1 = create_node(1);
    Node* n2 = create_node(2);
    Node* n3 = create_node(3);
    Node* n4 = create_node(4);
    Node* n5 = create_node(5);

    // Define connections
    add_connection(n1, n2);
    add_connection(n1, n5);
    add_connection(n2, n4);
    add_connection(n2, n3);

    // Perform BFS starting from node 1
    printf("BFS Traversal: ");
    DFS(n1);
    printf("\n");

    return 0;
}