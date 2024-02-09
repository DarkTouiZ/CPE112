//66070501060 ADISORN PARAMA
//Assignment 3.3 : Reverse Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int data);
Node *addNode(Node *Head, Node *newNode);
Node *reverseList(Node *Head, int startIdx, int stopIdx);
void swap(Node* n1, Node *n2);
void displayList(Node *Head);

int main(){
    char str[10001];
    int val = 1;

    Node *Head = NULL;
    while(val != 0){
        scanf(" %s", str);
        val = atoi(str);
        if(val != 0){
            Node *newNode = assignNode(newNode, val);
            Head = addNode(Head, newNode);
        }
    }

    int startIdx, stopIdx;
    scanf("%d %d", &startIdx, &stopIdx);
    Head = reverseList(Head, startIdx, stopIdx);

    displayList(Head);
    return 0;
}

Node *assignNode(Node *newNode,int  data){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *Head, Node *newNode){
    if(Head == NULL){
        Head = newNode;
        return Head;
    }

    Node *curr = Head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = newNode;
    return Head;
}

Node *reverseList(Node *Head, int startIdx, int stopIdx){
    if(startIdx == stopIdx || stopIdx + 1 == startIdx){
        return Head;
    }

    Node *curr = Head;
    Node *currBegin = NULL;
    for(int i = 1; i < stopIdx; ++i){
        if(i == startIdx){
            currBegin = curr;
        }
        curr = curr->next;
    }
    Node *currLast = curr;
    swap(currBegin, currLast);

    return reverseList(Head, startIdx+1, stopIdx-1);
}

void swap(Node *n1, Node *n2){
    int tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
}

void displayList(Node *Head){
    for(Node *curr = Head; curr != NULL; curr = curr->next){
        printf("%d ", curr->data);
    }
}