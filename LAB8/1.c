// 66070501060  ADISORN PARAMA
// Group Lab : Weighted Directed Graph Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int initial;
    int terminal;
    int weight;
    struct edge *next;
} edge;

typedef struct graph {
    int numVertices;
    edge **adjLists;
}graph;

graph *createGraph(int vertices);
void addEdge(graph *graph, int initial, int terminal, int weight);
void sortEdgesbyTerminal(graph *graph);
void sortEdgesbyWeight(graph *graph);
void printGraph(graph *graph);

int main(){
    int numEdges;
    scanf("%d", &numEdges);

    graph *graph = createGraph(numEdges);
    for(int i = 0; i < numEdges; i++){
        int initial, terminal, weight;
        scanf("%d %d %d", &initial, &terminal, &weight);
        addEdge(graph, initial, terminal, weight);
    }
    sortEdgesbyTerminal(graph);

    printGraph(graph);
    return 0;
}

// Create graph
graph *createGraph(int vertices) {
    graph *graph = malloc(sizeof(graph));
    graph->numVertices = vertices;
    // Create array of adjacency lists for each vertex
    graph->adjLists = malloc(vertices * sizeof(edge*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Create edge between two vertices with weight add to the adjacency list of the initial vertex
void addEdge(graph *graph, int initial, int terminal, int weight) {
    // Create new edge
    edge *newEdge = (edge *)malloc(sizeof(edge));
    newEdge->initial = initial;
    newEdge->terminal = terminal;
    newEdge->weight = weight;
    //add edge by sort weight
    if(graph->adjLists[initial] == NULL){
        graph->adjLists[initial] = newEdge;
        newEdge->next = NULL;
    }else{
        edge *tmp = graph->adjLists[initial];
        edge *prev = NULL;
        while(tmp != NULL){
            if(tmp->weight > weight){
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        if(prev == NULL){
            newEdge->next = graph->adjLists[initial];
            graph->adjLists[initial] = newEdge;
        }else{
            prev->next = newEdge;
            newEdge->next = tmp;
        }
    }
}

void sortEdgesbyTerminal(graph *graph){
    for(int i = 0; i < graph->numVertices; i++){
        edge *tmp = graph->adjLists[i];
        while(tmp){
            edge *tmp2 = tmp->next;
            while(tmp2){
                if(tmp->terminal > tmp2->terminal){
                    int temp; 
                    temp= tmp->terminal;
                    tmp->terminal = tmp2->terminal;
                    tmp2->terminal = temp;

                    temp = tmp->initial;
                    tmp->initial = tmp2->initial;
                    tmp2->initial = temp;

                    temp = tmp->weight;
                    tmp->weight = tmp2->weight;
                    tmp2->weight = temp;
                }
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
    }
}

void sortEdgesbyWeight(graph *graph){
    for(int i = 0; i < graph->numVertices; i++){
        edge *tmp = graph->adjLists[i];
        while(tmp){
            edge *tmp2 = tmp->next;
            while(tmp2){
                if(tmp->weight > tmp2->weight){
                    int temp; 
                    temp= tmp->terminal;
                    tmp->terminal = tmp2->terminal;
                    tmp2->terminal = temp;

                    temp = tmp->initial;
                    tmp->initial = tmp2->initial;
                    tmp2->initial = temp;

                    temp = tmp->weight;
                    tmp->weight = tmp2->weight;
                    tmp2->weight = temp;
                }
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
    }
}

// Print the graph
void printGraph(graph *graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        edge *tmp = graph->adjLists[v];
        while(tmp){
            printf("%d -> %d (%d)\n", tmp->initial, tmp->terminal, tmp->weight);
            tmp = tmp->next;
        }
    }
}
