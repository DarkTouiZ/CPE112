//60070501060 ADISORN PARAMA
//Lab 3.4 : Linked List that can Go Back
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int data);
Node *addNode(Node *DBLinkedList, Node *newNode);
Node *delKeyNode(Node *DBLinkedList, int key);
void SearchSideNode(Node *DBLinkedList, int key);
void displayList(Node **LinkedList);
void freeList(Node *DBLinkedList);
int main(){
    Node* DBLinkedList = NULL;
    char mode[4];
    do{
        scanf(" %s", mode);
        if(strcmp(mode, "ADD") == 0){
            int val;
            scanf("%d", &val);
            Node *newNode = assignNode(newNode, val);
            DBLinkedList = addNode(DBLinkedList, newNode);
        }else if(strcmp(mode, "DEL") == 0){
            int key;
            scanf("%d", &key);
            DBLinkedList = delKeyNode(DBLinkedList, key);
        }else if(strcmp(mode, "SCH") == 0){
            int key;
            scanf("%d", &key);
            SearchSideNode(DBLinkedList, key);
        }else if(strcmp(mode, "END") == 0){
            break;
        }else{
            printf("Invalid INPUT\n");
            break;
        }
    }while(1);

    displayList(&DBLinkedList);
    freeList(DBLinkedList);

    return 0;
}

Node *assignNode(Node *newNode, int data){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *DBLinkedList, Node *newNode){
    if(DBLinkedList == NULL){
        DBLinkedList = newNode;
        return DBLinkedList;
    }

    Node *tmp = DBLinkedList;
    while (tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = newNode;
    newNode->prev = tmp;

    return DBLinkedList;
}

Node *delKeyNode(Node *DBLinkedList, int key){
    Node *currNode = DBLinkedList;
    //NULL
    if(DBLinkedList == NULL){
        return DBLinkedList;
    }

    //LinkedList have 1 Node
    if(currNode->next == NULL){
        DBLinkedList = NULL;
        free(currNode);
        return DBLinkedList;
    }

    //del Head
    if(currNode->data == key){
        DBLinkedList = DBLinkedList->next;
        DBLinkedList->prev = NULL;
        free(currNode);
        return DBLinkedList;
    }

    while(currNode->data != key){
        //key is not in list
        if(currNode->next == NULL){
            return DBLinkedList;
        }
        currNode = currNode->next;
    }
    //del tail
    if(currNode->next == NULL){
        currNode->prev->next = NULL;
        free(currNode);
        return DBLinkedList;
    }else{
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        free(currNode);
        return DBLinkedList;
    }
    return DBLinkedList;
}

void SearchSideNode(Node *DBLinkedList, int key){
    int found = 1;
    Node* currNode = DBLinkedList;
    while(currNode->data != key){
        //there is not Node in list
        if(currNode->next == NULL){
            found = 0;
            break;
        }
        currNode = currNode->next;
    }
    if(found == 0){
        printf("none");
        printf("\n");
    }else if(currNode->prev != NULL && currNode->next != NULL){
        printf("%d %d", currNode->prev->data, currNode->next->data);
        printf("\n");
    }else if(currNode->prev == NULL && currNode->next != NULL){
        printf("NULL %d", currNode->next->data);
        printf("\n");
    }else if(currNode->prev != NULL && currNode->next == NULL){
        printf("%d NULL", currNode->prev->data);
        printf("\n");
    }
}

void displayList(Node **LinkedList){
    if(*LinkedList == NULL){
        printf("none\nnone");
        return ;
    }
    Node *Curr = *LinkedList;
    while(Curr != NULL){
        printf("%d ", Curr->data);
        Curr = Curr->next;
    }
    printf("\n");
    Curr = *LinkedList;
    while (Curr->next != NULL)
    {
        Curr = Curr->next;
    }

    while (Curr != NULL)
    {
        printf("%d ", Curr->data);
        Curr = Curr->prev;
    }
}

