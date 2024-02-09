//66070501060 ADISORN PARAMA
//Lab 4.3 : Tower of Hanoi
#include <stdio.h>

int towerOfHanoi(int n, char from, char to, char another, int *count)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        (*count)++;
        return 1;
    }
    towerOfHanoi(n - 1, from, another, to, count);
    printf("Move disk %d from %c to %c\n", n, from, to);
    (*count)++;
    towerOfHanoi(n - 1, another, to, from, count);
}

int main()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    towerOfHanoi(n, 'A', 'C', 'B', &c);
    printf("Total moves: %d\n", c);
    return 0;
}