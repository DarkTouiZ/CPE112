#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_Vertex{
    int Initial;
    int Terminal;
} Pair;

typedef struct Linked{
    int Data;
    struct Linked* Next;
} Node;

int AbsVisited(int Num, int NumEdge){
    if(Num > 0){return Num;}
    else {return Num*-1 + NumEdge;}
}

Node* Push(Node* Head, int newData){
    Node* newNode = malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->Next = Head;

    return newNode;
}

Node* Pop(Node* Head){
    if(Head == NULL){return NULL;}

    Node* DelNode = Head;
    Head = Head->Next;

    free(DelNode);

    return Head;
}

int Top(Node** Head){
    return (*Head)->Data;
}

int isEmpty(Node* Head){
    if(Head == NULL){return 1;}
    return 0;
}

void InsertionSortMax(Pair EdgeList[], int NumEdge){
    for(int i=0; i<NumEdge; i++){
        int Max = i;
        for(int j=i + 1; j<NumEdge; j++){
            if(EdgeList[j].Terminal > EdgeList[Max].Terminal){
                Max = j;
            }
        }

        //Swap
        Pair Temp = EdgeList[i];
        EdgeList[i] = EdgeList[Max];
        EdgeList[Max] = Temp;
    }
}

void DFS(int Current, Pair EdgeList[], int NumEdge, int NumVertex){

    int Visited[2001];
    for(int i=0; i<=2001; i++){
        Visited[i] = 0;
    }

    Node* Head = NULL;
    Head = Push(Head, Current);

    do {

        Current = Top(&Head);
        Head = Pop(Head);

        if(Visited[AbsVisited(Current, NumEdge)] == 1){continue;}

        Visited[AbsVisited(Current, NumEdge)] = 1;
        printf("%d ", Current);

        for(int i=0; i<NumEdge; i++){
            if(EdgeList[i].Initial == Current && Visited[AbsVisited(EdgeList[i].Terminal, NumEdge)] == 0){
                
                Head = Push(Head, EdgeList[i].Terminal);

            }
        }

    } while ( ! isEmpty(Head) );
}

Node* enqueue(Node* Head, int newData){
    Node* newNode = malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->Next = NULL;

    if(Head == NULL){return newNode;}

    Node* Curr = Head;
    while(Curr->Next != NULL){Curr = Curr->Next;}

    Curr->Next = newNode;
    return Head;
}

Node* dequeue(Node* Head){
    if(Head == NULL){return NULL;}
    
    Node* DelCurr = Head;
    Head = Head->Next;

    free(DelCurr);

    return Head;
}

int Front(Node** Head){
    return (*Head)->Data;
}

void InsertionSortMin(Pair EdgeList[], int NumEdge){
    for(int i=0; i<NumEdge; i++){
        int Min = i;
        for(int j=i + 1; j<NumEdge; j++){
            if(EdgeList[j].Terminal < EdgeList[Min].Terminal){
                Min = j;
            }
        }

        //Swap
        Pair Temp = EdgeList[i];
        EdgeList[i] = EdgeList[Min];
        EdgeList[Min] = Temp;
    }
}

void BFS(int Current, Pair EdgeList[], int NumEdge, int NumVertex){

    int Visited[2001];
    for(int i=0; i<=2001; i++){
        Visited[i] = 0;
    }

    Node* Head = NULL;
    Head = enqueue(Head, Current);

    do {

        Current = Front(&Head);
        Head = dequeue(Head);

        if(Visited[AbsVisited(Current, NumEdge)] == 1){continue;}

        Visited[AbsVisited(Current, NumEdge)] = 1;

        printf("%d ", Current);

        for(int i=0; i<NumEdge; i++){
            if(EdgeList[i].Initial == Current && Visited[AbsVisited(EdgeList[i].Terminal, NumEdge)] == 0){

                Head = enqueue(Head, EdgeList[i].Terminal);

            }
        }

    } while ( ! isEmpty(Head) );
}

int main(){
    int Vertices; scanf("%d", &Vertices);
    int Edges; scanf("%d", &Edges);

    Pair EdgeList[Edges];
    for(int i=0; i<Edges; i++){
        scanf(" %d %d", &EdgeList[i].Initial, &EdgeList[i].Terminal);
    }

    int Start; scanf("%d", &Start);
    
    InsertionSortMin(EdgeList, Edges);
    BFS(Start, EdgeList, Edges, Vertices);
    
    printf("\n");

    InsertionSortMax(EdgeList, Edges);
    DFS(Start, EdgeList, Edges, Vertices);

    // for(int i=0; i<Edges; i++){
    //     printf("%d %d\n", EdgeList[i].Initial, EdgeList[i].Terminal);
    // }

    return 0;
}