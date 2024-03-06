// 66070501060  ADISORN PARAMA
// Assignment 6.2: Prefix to Postfix

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(char data);
int addNode(Node **root, char data);
void postOrder(Node *root);

int main(){
    Node *root;
    char expression[101];
    scanf("%s", expression);

    for(int i = 0; expression[i] != '\0'; i++){
        addNode(&root, expression[i]);
    }
    postOrder(root);
    return 0;
}

Node *createNode(char data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//add Node to the tree in prefix order
int addNode(Node **root, char data){
    int added = 0;
    if(*root == NULL){
        *root = createNode(data);
        return 1;
    }else if((*root)->data == '+' || (*root)->data == '-'){
        //added is used to check if the node is added to the left or right
        added = addNode(&(*root)->left, data);
        if(added == 0){
            added = addNode(&(*root)->right, data);
        }
    }else{
        return 0;
    }
    return added;
}

void postOrder(Node *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->data);
}