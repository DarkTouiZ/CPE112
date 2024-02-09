//Adisorn Parama 660705001060  
// Spiral Array Printer

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int row;
  int col;
  int **data;
} Matrix;

Matrix *createMatrix(int row, int col);
void printSpiral(Matrix *matrix);
void freeMatrix(Matrix *matrix);

int main(void)
{
  int row, col;
  scanf("%d %d", &row, &col);
  //invalid case (out of range)
  if(row <= 0 || col <= 0)
    return 1;

  Matrix *matrix = createMatrix(row, col);
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++){
      scanf("%d", &matrix->data[i][j]);
    }
  }

  printSpiral(matrix);
  freeMatrix(matrix);
  return 0;
}

Matrix *createMatrix(int row, int col)
{
  Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
  matrix->row = row;
  matrix->col = col;
  matrix->data = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++){
    matrix->data[i] = (int *)malloc(col * sizeof(int));
  }
  return matrix;
}

void printSpiral(Matrix *matrix){
  int top = 0, bottom = matrix->row - 1, left = 0, right = matrix->col - 1;
  while(top <= bottom && left <= right){
    for(int i = left; i <= right; i++){
      printf("%d ", matrix->data[top][i]);
    }
    top++;
    for(int i = top; i <= bottom; i++){
      printf("%d ", matrix->data[i][right]);
    }
    right--;
    if(top <= bottom){
      for(int i = right; i >= left; i--){
        printf("%d ", matrix->data[bottom][i]);
      }
      bottom--;
    }
    if(left <= right){
      for(int i = bottom; i >= top; i--){
        printf("%d ", matrix->data[i][left]);
      }
      left++;
    }
  }
}

void freeMatrix(Matrix *matrix){
  for (int i = 0; i < matrix->row; i++){
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}