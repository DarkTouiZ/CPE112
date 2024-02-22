//66070501060 ADISORN PARAMA
//Lab 4.1 : Stack Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(int *stack,int *topIdx,int size, int newVal);
void pop(int *stack, int *topIdx);
void peek(int *stack, int *topIdx);
bool isFull(int *stack, int size);
bool isEmpty(int *top);

int main(){
    int size, top = -1;
    scanf(" %d", &size);
    if(size <= 0){
        printf("Please enter a positive number.");
        return 1;
    }

    int *stack = (int *)malloc(size * sizeof(int));
    if (stack == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    int mode;
    do{
        scanf("%d", &mode);
        if(mode == 1){
            //push
            int val;
            scanf("%d", &val);
            push(stack, &top, size, val);
        }else if(mode == 2){
            //pop
            pop(stack, &top);
        }else if(mode == 3){
            //show value in stack
            peek(stack, &top);
            break;
        }else if(mode == 4){
            printf("Exiting...");
            // free(stack);
            return 0;
        }else{
            printf("Invalid choice.");
            return 1;
        }
    }while(1);
    return 0;
}

void push (int *stack, int *topIdx, int size, int newval){
    if(isFull(topIdx, size)){
        printf("Stack Overflow.");
        exit(1);
    }else{
        *topIdx = *topIdx + 1;
        stack[*topIdx] = newval;
    }
}

void pop(int *stack, int *topIdx){
    if(isEmpty(topIdx)){
        printf("Stack Underflow.");
        exit(1);
    }else{
        *topIdx = *topIdx - 1;
    }
}

void peek(int stack[], int *topIdx){
    if(isEmpty(topIdx)){
        printf("Stack is empty.");
        exit(1);
    }else{
        for(int i = *topIdx; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

bool isFull(int *topIdx, int size){
    return *topIdx == size - 1;
}

bool isEmpty(int *topIdx){
    return *topIdx == -1;
}