// 66070501060  ADISORN PARAMA
// Lab 5.2 : When Will it Be My Turn???

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enqueue(int *queue, int *front, int *rear, int size, int val);
void dequeue(int *queue, int *front, int *rear, int size);
void display(int *queue, int front, int rear, int size);

int main(){
    int size;
    scanf("%d", &size);
    //invalid case
    if(size < 1 || size > 10){
        printf("Invalid size\n");
        return 1;
    }

    //create queue
    int *queue = (int *)malloc(size * sizeof(int));
    int front = -1, rear = -1;
    if(queue == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    char oper;
    while (1)
    {
        scanf(" %c", &oper);
        if(oper == 'I'){
            int val;
            scanf("%d", &val);
            enqueue(queue, &front, &rear, size, val);
        }else if(oper == 'D'){
            dequeue(queue, &front, &rear, size);
        }else if(oper == 'S'){
            display(queue, front, rear, size);
        }else if(oper == 'E'){
            break;
        }else{
            printf("Invalid command\n");
            return 1;
        }
    }
    free(queue);
    return 0;
}

void enqueue(int *queue, int *front, int *rear, int size, int val){
    if((*front == 0 && *rear == size - 1) || (*rear == *front - 1)){
        printf("Queue is full!!\n");
        return;
    }
    if(*front == -1){
        *front = 0;
        *rear = 0;
    }else if(*rear == size - 1){
        *rear = 0;
    }else{
        *rear = *rear + 1;
    }
    queue[*rear] = val;
}

void dequeue(int *queue, int *front, int *rear, int size){
    if(*front == -1){
        printf("Queue is empty!!\n");
        return;
    }
    
    int val = queue[*front];
    if(*front == *rear){
        //reset queue
        *front = -1;
        *rear = -1;
    }else if(*front == size - 1){
        //reset front
        *front = 0;
    }else{
        //move front
        *front = *front + 1;
    }
    //print value that dequeue
    printf("%d\n", val);
}

void display(int *queue, int front, int rear, int size){
    if(front == -1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n", front);
    printf("Items: ");
    if(rear >= front){
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }else{
        for(int i = front; i < size; i++){
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
    printf("Rear: %d\n", rear);
}

