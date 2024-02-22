//66070501060 ADISORN PARAMA
//Lab 3.2: Before or After Insertion
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *new(Node *node);
Node *assignNode(Node *newNode, int data);
Node *insertBefore(Node *Head, int key, Node *newNode);
Node *insertAfter(Node *Head, int key, Node *newNode);
Node *pushBack(Node *head, Node *newNode);
void displayList(Node **Head);
void freeList(Node *Head);

int main()
{
    Node *Head = NULL;
    int n;
    scanf("%d", &n);
    // invalid case
    if (n < 1)
    {
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        int val;
        scanf("%d", &val);
        Node *newNode = new (newNode);
        newNode = assignNode(newNode, val);
        Head = pushBack(Head, newNode);
    }
    char mode;
    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'A')
        {
            int key;
            int insertData;
            scanf("%d %d", &key, &insertData);
            Node *newNode = new (newNode);
            assignNode(newNode, insertData);

            insertAfter(Head, key, newNode);
        }
        else if (mode == 'B')
        {
            int key;
            int insertData;
            scanf("%d %d", &key, &insertData);
            Node *newNode = new (newNode);
            assignNode(newNode, insertData);

            Head = insertBefore(Head, key, newNode);
        }
        else
        {
            displayList(&Head);
            break;
        }
    }
    return 0;
}

Node *new(Node *node)
{
    node = (Node *)malloc(sizeof(Node));
    return node;
}

Node *assignNode(Node *newNode, int data)
{
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *pushBack(Node *Head, Node *newNode)
{
    if(Head == NULL){
        Head = newNode;
        return Head;
    }
    Node *curr = Head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return Head;
}

Node *insertBefore(Node *Head, int key, Node *newNode)
{
    if (Head == NULL)
    {
        Head = newNode;
        return Head;
    }
    Node *curr = Head;
    Node *prev = NULL;
    while (curr->data != key)
    {
        if (curr->next == NULL)
        {
            return Head;
        }
        prev = curr;
        curr = curr->next;
    }
    if(curr == Head){
        newNode->next = Head;
        Head = newNode;
        return Head;
    }
    newNode->next = curr;
    prev->next = newNode;
    return Head;
}

Node *insertAfter(Node *Head, int key, Node *newNode)
{
    if (Head == NULL)
    {
        Head = newNode;
        return Head;
    }
    Node *curr = Head;
    Node *prev = NULL;
    while (curr->data != key)
    {
        if(curr->next == NULL)
        {
            return Head;
        }
        prev = curr;
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return Head;
}

void displayList(Node **Head)
{
    for (Node *curr = *Head; curr != NULL; curr = curr->next)
    {
        printf("%d ", curr->data);
    }
}
