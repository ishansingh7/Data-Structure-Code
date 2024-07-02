#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

int queue[MAX];
int front = 0;
int rear = 0;

struct graph {
    int value;
    bool adj[MAX][MAX];
};

// Function to create a graph structure
struct graph *graph_create(int value) {
    struct graph *nn = (struct graph *)malloc(sizeof(struct graph));
    nn->value = value;
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < value; j++) {
            nn->adj[i][j] = false;
        }
    }
    return nn;
}

// Function to destroy graph structure
void graph_destroy(struct graph *nn) {
    free(nn);
}

// Adding elements to graph structure
void graph_addedge(struct graph *g, int value, int value1) {
    g->adj[value][value1] = true;
}

// BFS search
void graph_BFS(struct graph *g, int source) {
    // Mark all nodes as not visited
    bool visited[MAX];
    for (int i = 0; i < g->value; i++) {
        visited[i] = false;
    }

    // Mark the current node as visited and enqueue it
    visited[source] = true;
    queue[rear++] = source;

    while (front != rear) {
        source = queue[front++];
        printf("%d\n", source);
        for (int adjacent = 0; adjacent < g->value; adjacent++) {
            if (g->adj[source][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

int main() {
    // Create a graph
    struct graph *g = graph_create(4);
    graph_addedge(g, 0, 1);
    graph_addedge(g, 0, 2);
    graph_addedge(g, 1, 2);
    graph_addedge(g, 2, 0);
    graph_addedge(g, 2, 3);
    graph_addedge(g, 3, 3);

    printf("Following is Breadth First Traversal (starting from vertex 2) \n");
    graph_BFS(g, 2);
    graph_destroy(g);

    return 0;
}
