//66070501060 ADISORN PARAMA
//Lab 4.2 : Stack as Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int val);
void push(Node **top, int val);
void pop(Node **top);
void Top(Node *top);
void show(Node *top);
bool isEmpty(Node *top);
void freeStack(Node *top);

int main(){
    Node *top = NULL;
    char mode;
    do{
        scanf(" %c", &mode);
        if(mode == 'p'){
            //push
            int val;
            scanf("%d", &val);
            push(&top, val);
        }else if(mode == 'o'){
            //pop
            pop(&top);
        }else if(mode == 't'){
            //top
            Top(top);
        }else if(mode == 'e'){
            //empty
            printf("%d\n", isEmpty(top));
        }else if(mode == 's'){
            //show
            show(top);
        }else if(mode == 'q'){
            //exit
            freeStack(top);
            return 0;
        }else{
            printf("Invalid choice.\n");
            return 1;
        }
    }while(1);
}

Node *assignNode(Node *newNode, int val){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int val){
    Node *newNode = assignNode(newNode, val);
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top){
    if(isEmpty(*top)){
        printf("empty\n");
        return;
    }else{
        printf("%d\n", (*top)->data);
        Node *tmp = *top;
        *top = (*top)->next;
        free(tmp);
    }
}

void Top(Node *top){
    if(isEmpty(top)){
        printf("empty\n");
        return;
    }
    printf("%d\n", top->data);
}

void show(Node *top){
    if(isEmpty(top)){
        printf("empty\n");
        return;
    }else{
        Node *tmp = top;
        while(tmp != NULL){
            printf("%d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

bool isEmpty(Node *top){
    return top == NULL;
}

void freeStack(Node *top){
    while(top != NULL){
        Node *tmp = top;
        top = top->next;
        free(tmp);
    }
}