#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *assign(int val);
void enqueue(queue **pq, queue *newNode);
void dequeue(queue **pq);
void peek(queue **pq);
void display(queue **pq);
int minSum(int *arr);

int main(){
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("Invalid!");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        arr[i] = tmp; 
    }

    queue *pq = NULL;
    enqueue(&pq,assign(arr[0]));
    enqueue(&pq,assign(arr[1]));
    enqueue(&pq,assign(arr[2]));
    display(&pq);
    peek(&pq);

    //min Sum section
    int minsum = minSum(arr);
    printf("%d", minsum);
    return 0;
}

queue *assign(int val){
    queue *newNode = (queue*)malloc(sizeof(queue));
    if(newNode == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(queue **pq, queue *newNode){
    if(*pq == NULL){
        *pq = newNode;
    }else{
        queue *curr = *pq;
        queue *prev = NULL;
        if(newNode->data <= newNode->data){
            newNode->next = curr;
            return;
        }
        while (curr->data <= newNode->data){
            prev = curr;
            curr = curr->next;
            if(curr->next == NULL){
                curr->next = newNode;
                return;
            }
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

void dequeue(queue **pq){
    if(*pq == NULL){
        return;
    }else{
        queue *tmp = *pq;
        *pq = (*pq)->next;
        free(tmp);
    }
}

void peek(queue **pq){
    if(*pq == NULL){
        return;
    }else{
        printf("%d\n", (*pq)->data);
    }
}

void display(queue **pq){
    queue *tmp = *pq;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int minSum(int *arr){
    queue *pq = NULL;
    int num1, num2;
    for(int i = 0; i < (sizeof(arr)/ sizeof(arr[0])); i++){
        enqueue(&pq, assign(arr[i]));
    }

    int multiplier = 1;
    while(pq != NULL){
        if(multiplier != 1){
            num1 = num1 * multiplier;
            num1 += pq->data * multiplier/10;
            if(pq != NULL){
                num2 = num2 * multiplier;
                num2 += pq->data * multiplier/10;
            }
        }
        multiplier *= 10;
        pq = pq->next;
    }
    return num1 + num2;
}
