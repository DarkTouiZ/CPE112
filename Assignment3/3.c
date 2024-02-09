// 66070501060 ADISORN PARAMA
// Assignment 4.3 : Parenthesis Checker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack{
    char data;
    struct stack *next;
}stack;

void push(stack **top, char val);
char pop(stack **top);
bool isEmpty(stack *top);
bool isMatch(char open, char close);
bool isBalanced(char *str);

int main(){
    char str[1001];
    scanf("%s", &str);
    if(isBalanced(str)){
        printf("The string is balanced");
    }else{
        printf("The string is not balanced");
    }
    
    return 0;
}

void push(stack **top, char val){
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

char pop(stack **top){
    if(isEmpty(*top)){
        return '\0';
    }
    stack *tmp = *top;
    *top = (*top)->next;
    char val = tmp->data;
    free(tmp);
    return val;
}

bool isEmpty(stack *top){
    return top == NULL;
}

bool isMatch(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }else if(open == '{' && close == '}'){
        return true;
    }else if(open == '[' && close == ']'){
        return true;
    }
    return false;
}

bool isBalanced(char *str){
    stack *top = NULL;
    for(int i = 0; i < strlen(str); ++i){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(&top, str[i]);
        }else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(isEmpty(top)){
                return false;
            }
            
            if(!isMatch(pop(&top), str[i])){
                return false;
            }
        }
    }
    return isEmpty(top);
}