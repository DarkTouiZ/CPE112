//Adisorn Parama 660705001060
//Multiplication Matrix
#include <stdio.h>

void assignMatrix(int rows, int col, int matrix[rows][col]);

int main(){
    int row1, col1;
    scanf(" %d %d", &row1, &col1);
    int matrix_n[row1][col1];
    assignMatrix(row1, col1, matrix_n);

    int row2, col2;
    scanf(" %d %d", &row2, &col2);
    int matrix_m[row2][col2];
    assignMatrix(row2, col2, matrix_m);

    int result[row1][col2];
    if(col1 == row2){
        for(int i=0; i<row1; i++){
            for(int j=0; j<col2; j++){
                result[i][j] = 0;
                for(int k=0; k<col1 && k<row2; k++){
                    result[i][j] += matrix_n[i][k] * matrix_m[k][j];
                }
            }
        }
    }
    else{
        printf("Not Compatible");
        return 0;
    }

    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void assignMatrix(int rows, int col, int matrix[rows][col]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }
}