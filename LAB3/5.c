//66070501060   ADISORN PARAMA
//Lab 3.5 : Circular Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int data){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node *pushBack(Node *Head, Node *newNode){
    if(Head == NULL){
        Head = newNode;
        Head->next = Head;
        return Head;
    }

    Node *currNode = Head;
    while (currNode->next != Head)
    {
        currNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->next = Head;
    return Head;
}
Node *delKeyNode(Node *Head, int key){
    //NULL case
    if(Head == NULL){
        return Head;
    }

    Node *currNode = Head, *prev = NULL;
    //1 Node case
    if(currNode->next == Head){
        Head = NULL;
        return Head;
    }
    //Head case
    if(currNode->data == key){
        prev = Head;
        while (prev->next != Head){
            prev = prev->next;
        }
        prev->next = currNode->next;
        //assign New Head
        Head = Head->next;
        //del oldHead
        free(currNode);      
        return Head;
    }
    while (currNode->data != key){
        prev = currNode;
        currNode = currNode->next;
    }
    //End case
    if(currNode->next == Head){
        prev->next = Head;
        free(currNode);
        return Head;
    }else{
        prev->next = currNode->next;
        free(currNode);
        return Head;
    }
    return Head;
}

void displayList(Node *Head){
    if(Head == NULL){
        printf("Empty\n");
        return;
    }

    Node* currNode = Head;
    do{
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }while(currNode != Head);
    printf("\n");
}

int main(){
    Node *Head = NULL;
    char mode;
    do{
        scanf(" %c", &mode);
        if(mode == 'I'){
            int data;
            scanf("%d", &data);
            Node *newNode = assignNode(newNode, data);
            Head = pushBack(Head, newNode);
            //displayList(Head);
        }else if(mode == 'D'){
            int key;
            scanf("%d", &key);
            Head = delKeyNode(Head, key);
        }
    }while(mode != 'E');
    displayList(Head);
    
    return 0;
}