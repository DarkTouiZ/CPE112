//66070501060   Adisorn Parama
//Assignment 3.1 : It's Sorting Time
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int ID;
    int score;
    struct Node *next;
}Node;

Node *assignNode(Node *newNode, int ID, int score);
Node *pushBack(Node *Head, Node *newNode);
int memberinList(Node *Head);
void SortbyID(Node **Head);
void SortbyScore(Node **Head);
void Swap(Node *Node1, Node *Node2);
void displayList(Node *Head);

int main(){
    int n;
    Node *Head = NULL;
    scanf("%d", &n);
    // invalid case
    if(n < 1 || n > 100){
        return 1;
    }

    for(int i = 0; i < n; i++){
        int ID, score;
        scanf("%d %d", &ID, &score);
        Node *newNode = assignNode(newNode, ID, score);
        Head = pushBack(Head, newNode);
    }

    int mode;
    scanf("%d", &mode);
    if(mode == 0){
        SortbyID(&Head);
    }else if(mode == 1){
        SortbyScore(&Head);
    }
    displayList(Head);
    return 0;
}

Node *assignNode(Node *newNode, int ID, int score){
    newNode = (Node *)malloc(sizeof(Node));
    newNode->ID = ID;
    newNode->score = score;
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

int memberinList(Node *Head){
    int i = 0;
    Node *curr = Head;
    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}
void Swap(Node *Node1, Node *Node2){
    int tmpID = Node1->ID, tmpScore = Node1->score;
    Node1->ID = Node2->ID;
    Node1->score = Node2->score;
    Node2->ID = tmpID;
    Node2->score = tmpScore;
}

void SortbyID(Node **Head){
    //Bubble sort
    bool swapped;
    for(Node *curr = *Head; curr->next != NULL; curr = curr->next){
        swapped = false;
        for(Node *currj = *Head; currj->next != NULL; currj = currj->next){
            if(currj->ID > currj->next->ID){
                Swap(currj, currj->next);
                swapped = true;
            }
        }
    }

}

void SortbyScore(Node **Head){
    //Bubble sort
    bool swapped;
    for(Node *curr = *Head; curr->next != NULL; curr = curr->next){
        swapped = false;
        for(Node *currj = *Head; currj->next != NULL; currj = currj->next){
            if(currj->score > currj->next->score){
                Swap(currj, currj->next);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
    }

}

void displayList(Node *Head){
    for(Node *curr = Head; curr != NULL; curr = curr->next){
        printf("%d ", curr->score);
    }
}