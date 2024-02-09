//66070501060 Adisorn Parama 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int rows, cols, primary = 0, secondary = 0;
	scanf("%d %d", &rows, &cols);
    if(rows != cols){
        printf("ERROR");
        return 0;
    }
	int **matrix = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int *)malloc(cols * sizeof(int));
	}
    // input matrix
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    // find primary and secondary diagonal
	for (int i = 0; i < rows && i < cols; i++) {
		primary += matrix[i][i];
        secondary += matrix[i][cols - i - 1];
	}
    // print answer
	printf("Primary: %d\nSecondary: %d", primary, secondary);
	free(matrix);
	 return 0;
 }