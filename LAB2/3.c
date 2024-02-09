//66070501060 ADISORN PARAMA
//Lab 3.3: Where to DELETE?
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *new(Node *newNode);
Node *assignNode(Node *newNode, int data);
Node *pushBack(Node *Head, Node *newNode);
Node *del_first(Node *Head);
Node *del_last(Node *Head);
Node *del_key(Node *Head, int key);
void displayList(Node **Head);
void freeList(Node *Head);

int main(){
    Node *Head = NULL; 
    int n;
    scanf("%d", &n);
    // invalid case
    if(n < 1){
        return 1;
    }

    for(int i = 0; i < n; ++i){
        int val;
        scanf("%d", &val);

        Node *newNode = new(newNode);
        newNode = assignNode(newNode, val);
        Head = pushBack(Head, newNode);
    }
    
    char mode;
    while(Head != NULL && mode != 'E'){
        scanf(" %c", &mode);
        if(mode == 'F'){
            Head = del_first(Head);
        }else if(mode == 'L'){
            Head = del_last(Head);
        }else if(mode == 'N'){
            int key;
            scanf("%d", &key);

            Head = del_key(Head, key);
        }else{
            break;
        }   
    }
    displayList(&Head);
    return 0;
}

void displayList(Node **Head){
    if(*Head == NULL){
        printf("none");
    }else{
        for(Node *curr = *Head; curr != NULL; curr = curr->next){
            printf("%d ", curr->data);
        }
        printf("\n");
    }
}

Node *new(Node *newNode){
    newNode = (Node *)malloc(sizeof(Node));
    return newNode;
}

Node *assignNode(Node *newNode, int data){
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *pushBack(Node *Head, Node *newNode){
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

Node *del_first(Node *Head){
    if(Head == NULL){
        return NULL;
    }else{
        Node *curr = Head;
        Head = Head->next;
        free(curr);
    }
    return Head;
}

Node *del_last(Node *Head){
    if(Head == NULL){
        return NULL;
    }

    Node *curr = Head;
    Node *prev = NULL;
    while(curr->next){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return Head;
}


Node *del_key(Node *Head, int key){
    if(Head == NULL){
        return NULL;
    }else{
        Node *curr = Head;
        Node *prev = NULL;
        while(curr->data != key){
            prev = curr;
            curr = curr->next;
            if(curr == NULL){
                return Head;
            }
        }
        if(curr == Head){
            Node *tmp = Head;
            Head = Head->next;
            free(tmp);

            return Head;
        }
        prev->next = curr->next;
        free(curr);
    }
    return Head;
}
