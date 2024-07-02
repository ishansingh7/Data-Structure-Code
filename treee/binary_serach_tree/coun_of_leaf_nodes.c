#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newnode(int value) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// Function to count the number of nodes
int countnode(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countnode(root->left) + countnode(root->right);
}

int main() {
    struct node *root = newnode(5);
    root->left = newnode(4);
    root->right = newnode(10);
    root->right->right = newnode(12);
    root->left->right = newnode(3);
    
    int totalNodes = countnode(root);
    printf("Total number of nodes: %d\n", totalNodes);

    return 0;
}
