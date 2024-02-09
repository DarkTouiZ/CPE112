// 66070501060  Adisorn Parama   
// Jumping game
#include <stdio.h>
#include <stdlib.h>

int minJumps(int arr[], int startIndex, int endIndex);

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 0 || n > 1000)
        return 1;

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int minJump = minJumps(arr, 0, n - 1);
    if (minJump == 1000)
        printf("Not Possible\n");
    else
        printf("%d\n", minJump);

    return 0;
}

int minJumps(int arr[], int startIndex, int endIndex)
{
    
    if (endIndex == startIndex)
        return 0;

    if (arr[startIndex] == 0)
        return 1000;

    // Find the minimum jumps to reach endIndex from startIndex
    int min = 1000;
    for (int i = startIndex + 1, j = startIndex + arr[startIndex]; i <= endIndex && i <= j; i++)
    {
        int jumps = minJumps(arr, i, endIndex);
        if (jumps != 1000 && jumps + 1 < min)
        {
            min = jumps + 1;
        }
    }

    return min;
}