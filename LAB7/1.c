// 66070501060 ADISORN PARAMA
// Lab 7.1: Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createnode(data);
    if (data < root->data)
        root->left = insert(root->left, data); //Recursive
    else if (data > root->data)
        root->right = insert(root->right, data); //Recursive
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        if(root->left != NULL)
            preorder(root->left); //Recursive
        if(root->right != NULL)
            preorder(root->right); //Recursive
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct node* root) {
    if (root != NULL) {
        if(root->left != NULL)
            inorder(root->left); //Recursive
        printf("%d ", root->data);
        if(root->right != NULL)
            inorder(root->right); //Recursive
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct node* root) {
    if (root != NULL) {
        if(root->left != NULL)
            postorder(root->left); //Recursive
        if(root->right != NULL)
            postorder(root->right); //Recursive
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &data);
        root = insert(root, data); //Recursive
    }

    //Preorder traversal: 
    preorder(root);
    printf("\n");
    //Inorder traversal: 
    inorder(root);
    printf("\n");
    //Postorder traversal: 
    postorder(root);
    printf("\n");

    return 0;
}