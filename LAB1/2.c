//66070501060 Adisorn Parama 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    // array of size n is declared
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);

    //find the largest and the smallest element in array
    int largest = *arr, smallest = *arr, largest_index = 0, smallest_index = 0;
    for(int i=1; i<n; i++)
    {
        if(*(arr+i) > largest)
        {
            largest = *(arr+i);
            largest_index = i;
        }
        if(*(arr+i) < smallest)
        {
            smallest = *(arr+i);
            smallest_index = i;
        }
    }

    //print answer
    printf("%d %d", largest, largest_index);
    printf("\n%d %d", smallest, smallest_index);

    return 0;
}