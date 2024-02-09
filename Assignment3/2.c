// 66070501060 ADISORN PARAMA
// Assignment 4.2 : Palindrome Checker
#include <stdio.h>
#include <string.h>

int isPalin(char *str, int left, int right);

int main(){
    char str[255];
    scanf("%s", str);
    int left = 0, right = strlen(str) - 1;
    if(isPalin(str, left, right)){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}

int isPalin(char *str, int left, int right){
    if(left >= right){
        return 1;
    }if(str[left] != str[right]){
        return 0;
    }
    return isPalin(str, left + 1, right - 1);
}