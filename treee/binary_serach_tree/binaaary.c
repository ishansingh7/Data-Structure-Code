#include <stdio.h>
#include <stdlib.h>

// defining the structures for bst
struct binarytree{
    int data;
    struct binarytree *left, *right;
};

// creating the new node to give value
struct binarytree* create_binarytree(int val){
    struct binarytree *nn=(struct binarytree*)malloc(sizeof(struct binarytree));
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

// BST for insertion in tree
struct binarytree* insert_binarytree(struct binarytree* root, int val){
    if (root == NULL) {
        return create_binarytree(val);
    } else  {
        if (val < root->data) {
           root->left = insert_binarytree(root->left, val);
        } else {
            root->right = insert_binarytree(root->right, val);
        }
        return root;
    }
}

// search for a value in the binary tree
struct binarytree* search_binarytree(struct binarytree* root, int val ){
    if (root == NULL || root->data == val) {
        return root;
    }

    // Key is smaller than root's key
    if (val < root->data) {
        return search_binarytree(root->left, val);
    }
    
    // Key is greater than root's key
    return search_binarytree(root->right, val);
}

// find minimum value in the BST
struct binarytree* min(struct binarytree* root){
    if(root == NULL || root->left == NULL) {
        return root;
    }
    return min(root->left);
}
// find maximum value in the BST
struct binarytree* max(struct binarytree* root){
    if(root==NULL || root->right == NULL) {
        return root;
}
else{
    return min(root->right);
}

}
//preorder
void preorder(struct binarytree* root){
    if(!root){
        return;
    }
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct binarytree *root = NULL;
    // Insert nodes into the BST
    root = create_binarytree(50);
    root = insert_binarytree(root, 30);
    root = insert_binarytree(root, 20);
    root = insert_binarytree(root, 40);
    root = insert_binarytree(root, 70);
    root = insert_binarytree(root, 60);
    root = insert_binarytree(root, 80);

    // You can print inorder traversal or anything else you want to do with the tree here
    
    printf("Preorder traversal of the BST: \n");
    preorder(root);
    printf("\n----------------------------------------------------------------\n");
    //search for nodes
    int val = 60;
    struct binarytree* result = search_binarytree(root, val);
    if (result != NULL) {
        printf("Key %d found in the BST.\n", val);
    } else {
        printf("Key %d not found in the BST.\n", val);
    }

    // Find minimum value
    printf("Minimum value in the BST: %d\n", min(root)->data);
    printf("Maximum value in the BST: %d\n", max(root)->data);

    return 0;
}
