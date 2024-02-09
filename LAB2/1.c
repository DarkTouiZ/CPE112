//66070501060  ADISORN PARAMA
//Lab 3.1: Linked List Insertion
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *new(Node *node)
{
    node = (Node *)malloc(sizeof(Node));
    return node;
}

Node *assignNode(Node *node, int data)
{
    node->data = data;
    node->next = NULL;
    return node;
}

Node *insertBegin(Node *Head, Node *newNode)
{
    if(Head == NULL){
        Head = newNode;
    }else{
        newNode->next = Head;
        Head = newNode;
    }
    return Head;
}

Node *insertEnd(Node *Head, Node *newNode)
{
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        Node *ptr = Head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return Head;
}

void displayList(Node **Head)
{
    for(Node *curr = *Head; curr != NULL; curr = curr->next){
        printf("%d ", curr->data);
    }
}


void freeList(Node *Head){
    while (Head != NULL)
    {
        Node *curr = Head;
        Head = Head->next;
        free(curr);
    }
}

int main()
{
    Node *Head = NULL;

    // input Number of Node and Mode
    int n, mode;
    scanf("%d", &n);
    scanf("%d", &mode);
    // invalid case
    if (n < 1 )
    {
        printf("Invalid");
        return 1;
    }

    // insert node following mode
    if (mode == 1)
    {
        // insert node from begin
        int val;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &val);
            Node *newNode = new(newNode);
            newNode = assignNode(newNode, val);
            Head = insertBegin(Head, newNode);
        }
    }
    else if (mode == 2)
    {
        // insert node from end
        int val;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &val);
            Node *newNode = new (newNode);
            newNode = assignNode(newNode, val);
            Head = insertEnd(Head, newNode);
        }
    }else{
        printf("Invalid");
        return 1;
    }

    // print Result
    displayList(&Head);
    freeList(Head);
    return 0;
}

