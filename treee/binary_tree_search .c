#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *insert(struct node *r, int value) {
    if (r == NULL) {
        r = newNode(value);
        return r;
    } else {
        if (value < r->data) {
            r->left = insert(r->left, value);
        } else {
            r->right = insert(r->right, value);
        }
        return r;
    }
}

// Inorder travers
void printinorder(struct node *node) {
    if (node == NULL)
        return;
    printinorder(node->left);
    printf("%d\n", node->data);//root node
    printinorder(node->right);
}

// Preorder traversal
void printpreorder(struct node *node) {
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}

// Postorder traversal
void printpostorder(struct node *node) {
    if (node == NULL)
        return;
    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d\n", node->data);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 45);
    root = insert(root, 20);
    root = insert(root, 20); 
    root = insert(root, 23);
    root = insert(root, 60);
    printf("Inorder traversal of binary tree is: \n");
    printinorder(root);
    printf("\n");

    printf("Preorder traversal of binary tree is: \n");
    printpreorder(root);
    printf("\n");

    printf("Postorder traversal of binary tree is: \n");
    printpostorder(root);
    printf("\n");

    return 0;
}
