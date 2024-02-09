// 66070501060 ADISORN PARAMA
// Assignment 4.1 : Ten to X
#include <stdio.h>
#include <stdlib.h>

typedef struct digit{
    char data;
    struct digit *next;
}digit;

char Int_into_Char(int num);
digit *assignDigit(digit *Digit, char val);
digit *addDigit(digit *Digit, digit *newDigit);
void convertBase(int n, int x, digit **Digit);
void print(digit *Digit);
void freeList(digit *Digit);

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    if(x < 2 || x > 36){
        printf("invalid\n");
        return 1;
    }

    //convert to base X
    digit *Digit = NULL;
    convertBase(n, x, &Digit);
    print(Digit);
    freeList(Digit);
    return 0;
}

char Int_into_Char(int num){
    if(num >= 0 && num <= 9){
        return (char)(num + '0');
    }else{
        return (char)(num - 10 + 'A');
    }
}

void convertBase(int n, int x, digit **Digit){
    while(n > 0){
        digit *newDigit = assignDigit(newDigit, Int_into_Char(n % x));
        *Digit = addDigit(*Digit, newDigit);
        n = n / x;
    }
}

digit *assignDigit(digit *newDigit, char val){
    newDigit = (digit *)malloc(sizeof(digit));
    newDigit->data = val;
    newDigit->next = NULL;
}

digit *addDigit(digit *Digit, digit *newDigit){
    newDigit->next = Digit;
    Digit = newDigit;
}

void print(digit *Digit){
    while(Digit != NULL){
        printf("%c", Digit->data);
        Digit = Digit->next;
    }
    printf("\n");
}

void freeList(digit *Digit){
    while(Digit != NULL){
        digit *tmp = Digit;
        Digit = Digit->next;
        free(tmp);
    }
}