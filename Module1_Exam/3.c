#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 15

void push(char *stack, int *top, char newVal);
void pop(char *stack, int *top);
void peek(char *stack, int *top);
void display(char *stack, int top);
bool isFull(int *stack, int size);
bool isEmpty(int *top);
void shortenString(char word[], char *s, int *top);
void displayShorten(char *s, int *top);


int main()
{
    int top = -1;
    char word[MAX];
    scanf(" %s", word);
    if(strlen(word) > 10){
        printf("String Overflow!");
        exit(1);
    }

    char *s = (char*)malloc(MAX * sizeof(char));
    if(s == NULL){
        printf("Memory allocation failed.");
        return 1;
    }

    push(s, &top, word[0]);
    push(s, &top, word[1]);
    push(s, &top, word[2]);
    display(s, top);
    peek(s, &top);
    pop(s, &top);
    pop(s, &top);
    display(s, top);

    //new stack for shortenString function
    int top1 = -1;
    char *s1 = (char*)malloc(MAX * sizeof(char));
    shortenString(word, s1, &top1);
    if(isEmpty(&top1)){
        printf("Empty String!");
    }else{
        displayShorten(s1, &top1);
    }
    //----------
    return 0;
}

void push(char *stack, int *top, char newVal){
    if(isFull(top, MAX)){
        printf("Stack Overflow.");
        exit(1);
    }else{
        *top = *top + 1;
        stack[*top] = newVal;
    }
}

void pop(char *stack, int *top){
    if(isEmpty(top)){
        printf("Stack Underflow");
        exit(1);
    }else{
        *top = *top - 1;
    }
}

void peek(char *stack, int *top){
    if(isEmpty(top)){
        printf("Empty String");
        exit(1);
    }else{
        printf("%c\n", stack[*top]);
    }
}

void display(char *stack, int top){
    if(isEmpty(&top)){
        printf("Empty String");
        exit(1);
    }else{
        for(int i = 0; i <= top; i++){
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}
bool isFull(int *topIdx, int size){
    return *topIdx == size - 1;
}

bool isEmpty(int *topIdx){
    return *topIdx == -1;
}

void shortenString(char word[], char *s, int *top){
    for(int i = 0; i < strlen(word); i++){
        if(*top == -1 || word[i] != word[i-1]){
            push(s, top, word[i]);
        }else{
            pop(s, top);
        }
    }
}

void displayShorten(char *s, int *top){
    if(isEmpty(top)){
        printf("Empty String");
        exit(1);
    }else{
        for(int i = 0; i <= *top; i++){
            printf("%c", s[i]);
        }
        printf("\n");
    }
}