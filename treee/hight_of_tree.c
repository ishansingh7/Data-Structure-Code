#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *NewNode(int value) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// Function to calculate the height of the tree
int height_of_tree(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    int height1 = height_of_tree(root->left);
    int height2 = height_of_tree(root->right);

    if (height1 > height2) {
        return height1 + 1;
    } else {
        return height2 + 1;
    }
}

int main() {
    struct node *root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);

    int height = height_of_tree(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
