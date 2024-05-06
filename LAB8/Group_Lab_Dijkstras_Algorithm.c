#include <stdio.h>

#define INF 999
//case infinity cannot reach

struct vertex {    //to store vertex and
  int vertex;      //path form source to it
  int path;
  int isVisited;
};

//label vertex and INF weight for every node, src node = 0
void initialize(int v, int src, struct vertex vertex[]) {
  for (int i=0; i < v; i++) {
    vertex[i].vertex = i;
    vertex[i].path = INF;
    vertex[i].isVisited = 0;
  }
  vertex[src].path = 0;  // for source node label it 0
}

//min() for return the nearest node
int min(int v, struct vertex vertex[]) {
  int min = INF;
  int minNode = 0;
  for (int i=0; i < v; i++) {
    if (!(vertex[i].isVisited) && vertex[i].path < min) {
      min = vertex[i].path;
      minNode = i;
    }
  }
  return minNode;
}

void dijkstra(int v, struct vertex vertex[], int adjWM[][100]) {
  for (int i=0; i < v; i++) {
    int nearestNode = min(v, vertex);
    vertex[nearestNode].isVisited = 1;

    for (int neighbor = 0; neighbor < v; neighbor++) {
      if (adjWM[nearestNode][neighbor] != 0 &&
        vertex[neighbor].path > vertex[nearestNode].path + adjWM[nearestNode][neighbor])
      {
        vertex[neighbor].path = vertex[nearestNode].path + adjWM[nearestNode][neighbor];
        // printf("%d %d\n", neighbor, vertex[neighbor].path);
        //vertex[neighbor].vertex = nearestNode; //***
      }
    }
  }
}

void show(int v, struct vertex vertex[]) {
  for (int i=0; i < v; i++) {
    printf("%d %d\n", vertex[i].vertex, vertex[i].path);
  }
}

int main(void) {
  struct vertex vertex[100];
  int v, src, adjWM[100][100]; //adjacency weigh matrix

  scanf(" %d", &v); //input number of vertex
  scanf(" %d", &src); // input source node
  for (int i=0; i < v; i++) {
    for (int j=0; j < v; j++) {
      scanf(" %d", &adjWM[i][j]);
    }
  }
  initialize(v, src, vertex);
  dijkstra(v, vertex, adjWM);
  show(v, vertex);
  // for (int i=0; i<v; i++) {
  //   printf("%d %d\n", vertex[i].vertex, vertex[i].path);
  // }
  
  
  return 0;
}