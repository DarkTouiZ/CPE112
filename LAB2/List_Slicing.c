// 66070501060 ADISORN PARAMA
// Challenge: List Slicing
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST
{
    int size;
    int *arr;
} LIST;

LIST *assignList();

void append(LIST *list, int val);
void printList(LIST *list);
int assignStartEnd(int idx, int size);
LIST *slice(LIST *list, int start, int end, int step);
void freeList(LIST *list);

int main()
{
    LIST *list = assignList();
    int n;
    scanf("%d", &n);
    // Invalid case
    if (n < 1 || n > 1000000){
        return 1;
    }

    for (int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        append(list, tmp);
    }

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    LIST *sliced = slice(list, start, end, step);
    printList(sliced);

    freeList(list);
    freeList(sliced);
    return 0;
}

LIST *assignList()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    list->size = 0;
    list->arr = NULL;
    return list;
}

void append(LIST *list, int val)
{
    list->size++;
    list->arr = (int *)realloc(list->arr, list->size * sizeof(int));
    list->arr[list->size - 1] = val;
}

void printList(LIST *list)
{
    if (list->size == 0)
    {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int assignStartEnd(int idx, int size)
{
    // Negative index = counting from the end.
    if (idx < 0)
    {
        idx = size + idx;
    }
    // Ensure the index is non-negative.
    if (idx < 0)
    {
        idx = 0;
    }
    // Ensure the index is within bounds.
    else if (idx > size)
    {
        idx = size;
    }

    return idx;
}

LIST *slice(LIST *list, int start, int end, int step)
{
    // Initialize the sliced list
    LIST *sliced = assignList();
    // Assign the start and end index
    start = assignStartEnd(start, list->size);
    end = assignStartEnd(end, list->size);

    if (start == list->size && step < 0)
    {
        start--;
    }

    // If the step is 0, return the empty list.
    if (step == 0)
    {
        return sliced;
    }

    if (step > 0)
    {
        for (int i = start; i < end; i += step)
        {
            append(sliced, list->arr[i]);
        }
    }
    else
    {
        for (int i = start; i > end; i += step)
        {
            append(sliced, list->arr[i]);
        }
    }

    return sliced;
}

void freeList(LIST *list)
{
    free(list->arr);
    free(list);
}