//66070501060 ADISORN PARAMA 
//Assignment 3.2 : Circular table
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int val);
Node *addNode(Node *Head, Node *newNode);
Node *findResult(Node *Head, int step);

int main(){
    Node *Head = NULL;
    int n, step;
    scanf("%d %d", &n, &step);
    for(int i = 0; i < n; ++i){
        int val;
        scanf("%d", &val);
        Node *newNode = assignNode(newNode, val);
        Head = addNode(Head, newNode);
    }
    Head = findResult(Head,step);
    printf("%d", Head->data);
    return 0;
}

Node *assignNode(Node *newNode, int data){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *Head, Node *newNode){
    if(Head == NULL){
        Head = newNode;
        Head->next = Head;
        return Head;
    }

    Node *curr = Head;
    while(curr->next != Head){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = Head;
    return Head;
}

Node *findResult(Node *Head, int step){
    // base case result was found !!
    if(Head->next == Head){
        return Head;
    }

    Node *curr = Head, *prev = NULL;
    for(int i = 0; i < step-1; i++){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    return findResult(prev->next, step);
}
