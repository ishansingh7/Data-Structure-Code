// directed graph

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int dest;
    struct Node* next;
};
struct Graph {
    int V; // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};
struct Node* newNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}