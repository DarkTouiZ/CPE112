// 66070501060  ADISORN PARAMA
// Assignment 6.1 : Sum Tree

#include <stdio.h>
#include <stdlib.h>

int sumTree(int *tree, int n, int index);

int main(){
    int *tree = malloc(1000 * sizeof(int));
    if(tree == NULL){
        printf("memory allocation failed");
        return 1;
    }
    int val, index = 0;
    
    while(1){
        scanf("%d", &val);
        if(val == -1001)
            break;
        
        tree[index] = val;
        index++;
    }

    int result = sumTree(tree, index, 0);
    if(index == 1 || result/2 == tree[0])
        printf("True\n");
    else    
        printf("False\n");

    free(tree);

    return 0;
}

int sumTree(int *tree, int n, int index){
    if(index >= n)
        return 0;
    
    int left = sumTree(tree, n, 2*index + 1);
    int right = sumTree(tree, n, 2*index + 2);

    return left + right + tree[index];
}