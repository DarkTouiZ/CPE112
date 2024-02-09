// 66070501060 Adisorn Parama  

#include <stdio.h>

void makeSet(int *set,int *numElement)
{
    int numMember = 0;
    for(int i=0; i < *numElement; i++){
        int tmp;
        scanf("%d",&tmp);
        if(numMember==0){
            set[numMember] = tmp;
            numMember++;
        }else{
            
            if(set[numMember-1] != tmp){
                set[numMember] = tmp;
                numMember++;
            }
        }
    }
    *numElement = numMember;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 1 || n > 1000){
        return 0;
    }
    int set[n];
    makeSet(set, &n);
    
    printf("%d\n", n);
    for(int i=0; i<n;i++){
        printf("%d ", set[i]);
    }
    return 0;
}