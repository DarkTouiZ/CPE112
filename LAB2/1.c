//66070501060 Adisorn Parama 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    int mode;
    scanf("%d",&mode);
    int printed =  0;
    
    if(mode == 0){
        //print value in even index
        for(int i=0;i<n;i+=2)
        {
            printf("%d ",*(arr+i));
            printed++;
        }
    }else{
        //print value in odd index
        for(int i=1;i<n;i+=2)
        {
            printf("%d ",*(arr+i));
            printed++;
        }
    }
    if(printed == 0)
    {
        printf("none");
    }
    return 0;
}