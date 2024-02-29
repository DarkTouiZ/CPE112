// 66070501060  ADISORN PARAMA
// Lab 5.3 : Secret Code Only You and I Know

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char name;
    int priority;
    struct node *next;
} node;

int isVowel(char c);
int priority(char c);
void insert(node **head, char c);
void print(node *head);

int main(void)
{
    char input[1000];
    fgets(input, 1000, stdin);
    input[strlen(input) - 1] = '\0';
    node *head = NULL;
    for (int i = 0; i < strlen(input); i++)
    {
        insert(&head, input[i]);
    }
    print(head);
    return 0;
}

void insert(node **head, char c)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->name = c;
    newNode->priority = priority(c);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void print(node *head)
{
    node *curr = head;
    for (int i = 3; i > 0; i--)
    {
        while (curr != NULL)
        {
            if (curr->priority == i)
            {
                printf("%c", curr->name);
            }
            curr = curr->next;
        }
        curr = head;
    }
    printf("\n");
}

int isVowel(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int priority(char c)
{
    if (isVowel(c))
    {
        return 3;
    }
    else if (isalpha(c))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}