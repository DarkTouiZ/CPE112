//Adisorn Parama 660705001060
//Multiplication Matrix

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int **data;
} Matrix;

Matrix *createMatrix(int row, int col);
Matrix *multiplyMatrix(Matrix *matrix1, Matrix *matrix2);
Matrix *assignMatrix(Matrix *matrix);
void freeMatrix(Matrix *matrix);
void printMatrix(Matrix *matrix);

int main()
{
    int row1, col1;
    scanf("%d %d", &row1, &col1);
    // invalid case
    if(row1 <= 0 || col1 <= 0 || row1 > 10 || col1 > 10)
        return 1;

    Matrix *matrix1 = createMatrix(row1, col1);
    matrix1 = assignMatrix(matrix1);
    // invalid case
    if(matrix1 == NULL)
        return 1;

    int row2, col2;
    scanf("%d %d", &row2, &col2);
    // invalid case
    if(row2 <= 0 || col2 <= 0 || row2 > 10 || col2 > 10)
        return 1;
    
    Matrix *matrix2 = createMatrix(row2, col2);
    matrix2 = assignMatrix(matrix2);
    // invalid case
    if(matrix2 == NULL)
        return 1;
    
    Matrix *result = multiplyMatrix(matrix1, matrix2);
    // invalid case
    if(result == NULL){
        printf("Not Compatible\n");
        return 1;
    }

    printMatrix(result);

    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(result);
    
    return 0;
}

Matrix *createMatrix(int row, int col)
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->col = col;
    matrix->data = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix->data[i] = (int *)malloc(col * sizeof(int));
    }
    return matrix;
}

Matrix *assignMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            scanf("%d", &matrix->data[i][j]);
            // invalid case
            if(matrix->data[i][j] < -1000 || matrix->data[i][j] > 1000)
                return NULL;
        }
    }
    return matrix;
}

Matrix *multiplyMatrix(Matrix *matrix1, Matrix *matrix2)
{
    // invalid case
    if(matrix1->col != matrix2->row)
        return NULL;

    Matrix *result = createMatrix(matrix1->row, matrix2->col);
    for (int i = 0; i < matrix1->row; i++)
    {
        for (int j = 0; j < matrix2->col; j++)
        {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->col; k++)
            {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

void printMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

