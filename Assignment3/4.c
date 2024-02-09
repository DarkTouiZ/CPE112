// 66070501060 ADISORN PARAMA
// Assignment 4.4 : Infix to Postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack
{
    char data;
    struct stack *next;
} stack;

void push(stack **top, char value);
char pop(stack **top);
bool isEmpty(stack *top);
int precedence(char operator);
void charToPostfix(char *infix, char *postfix);

int main(void)
{
    char infix[1000];
    scanf("%s", infix);
    char postfix[1000];
    charToPostfix(infix, postfix);
    printf("%s", postfix);
    return 0;
}

void push(stack **top, char value)
{
    stack *new = (stack *)malloc(sizeof(stack));
    new->data = value;
    new->next = *top;
    *top = new;
}

char pop(stack **top)
{
    if (isEmpty(*top))
    {
        return '\0';
    }
    char value = (*top)->data;
    stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

bool isEmpty(stack *top)
{
    return top == NULL;
}

void charToPostfix(char *infix, char *postfix)
{
    stack *oper = NULL;
    int infixLength = strlen(infix);
    int j = 0;
    // Scan infix from left to right
    for (int i = 0; i < infixLength; i++)
    {
        char temp = infix[i];
        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            // Operand
            postfix[j++] = temp;
        }
        else if (temp == '(')
        {
            // Open parenthesis
            push(&oper, temp);
        }
        else if (temp == ')')
        {
            // Close parenthesis
            while (!isEmpty(oper) && oper->data != '(')
            {
                // Pop operators to postfix until Open parenthesis
                postfix[j++] = pop(&oper);
            }
            pop(&oper); // Remove Open parenthesis
        }
        else
        {
            // Operator
            while (!isEmpty(oper) && precedence(temp) <= precedence(oper->data))
            {
                // Pop operators to postfix until precedence of current operator is higher than the top of the stack
                postfix[j++] = pop(&oper);
            }
            push(&oper, temp); // Push current operator to stack
        }
    }
    // Pop remaining operators to postfix
    while (!isEmpty(oper))
    {
        postfix[j++] = pop(&oper);
    }
    postfix[j] = '\0'; // Add null terminator
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '^')
        return 3;
    else
        return -1;
}
