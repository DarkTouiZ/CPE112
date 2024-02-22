//66070501060 Adisorn Parama 
#include<stdio.h>
#include<string.h>

typedef struct
{
    char key[100];
    char value[100];
} dict;

void editDict( int size, dict Dict[])
{
    char tmpK[100];
    char tmpV[100];
    scanf(" %s %s", tmpK, tmpV);
    for ( int i = 0; i < size; i++)
        if ( strcmp( tmpK, Dict[i].key) == 0)
        {
            strcpy( Dict[i].value, tmpV);
            return;
        }
    printf("No change\n");
}


void printDict( int size, dict Dict[])
{
    for ( int i = 0; i < size; i++)
        printf("%s : %s\n", Dict[i].key, Dict[i].value);
}

int main()
{   
    int size;
    scanf(" %d", &size);
    dict Dict[size];

    for ( int i = 0; i < size; i++)
        scanf(" %s %s", Dict[i].key, Dict[i].value);

    editDict(size, Dict);
    printDict(size, Dict);
    return 0;
}