#include<stdio.h>
#include<stdlib.h>

// A binary tree node has data, pointer to left child and a pointer to right child
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct node* node) {
    if (node == NULL) 
        return;
    // First recur on left child
    printInorder(node->left);
    // Then print the data of node
    printf("%d ", node->data);
    // Now recur on right child
    printInorder(node->right);
}

void printPreorder(struct node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left =newNode(7);
    root->right->right =newNode(10);
    printf("Inorder traversal of binary tree is: ");
    printInorder(root);
    printf("\n");

    printf("Preorder traversal of binary tree is: ");
    printPreorder(root);
    printf("\n");

    printf("Postorder traversal of binary tree is: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
