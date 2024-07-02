#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *NewNode(int data) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// Function to insert a new value into the binary search tree
struct node *insertion(struct node *root, int value) {
    if (root == NULL) {
        return NewNode(value);
    } else {
        if (value < root->data) {
            root->left = insertion(root->left, value);
        } else {
            root->right = insertion(root->right, value);
        }
        return root;
    }
}

// Function for inorder traversal
void inorder(struct node *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Function for preorder traversal
void preordered(struct node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preordered(node->left);
    preordered(node->right);
}

// Function for postorder traversal
void postordered(struct node *node) {
    if (node == NULL) {
        return;
    }
    postordered(node->left);
    postordered(node->right);
    printf("%d ", node->data);
}

int main(void) {
    struct node *root = NULL;
    int choice;
    while (1) {
        printf("1. Insertion\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to be inserted:\n");
                scanf("%d", &value);
                root = insertion(root, value);
                break;
            }
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preordered(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postordered(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
