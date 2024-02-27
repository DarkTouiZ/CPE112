#include <stdio.h>
#include <stdlib.h>

int *twoSum(int * nums, int numsSize, int target, int *returnSize, int *isSuccess);

int main(){
    int nums[10] = {1, 2, 3, 4 ,5, 1, 1 , 1, 1, 1};
    int target = 0;
    int numsSize = sizeof(nums)/ sizeof(nums[0]);
    int returnSize, isSuccess;
    int *result = twoSum(nums, numsSize, target, &returnSize, &isSuccess);
    if(isSuccess == 1){
        printf("Indices: ");
        for(int i = 0; i < returnSize; i++){
            printf("%d ", result[i]);
        }
    }else{
        printf("No two number add up to the target");
    }
    return 0;
} 

int *twoSum(int * nums, int numsSize, int target, int *returnSize, int *isSuccess){
    int *result = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i; j < numsSize - 1; j ++){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

/* โปรแกรมมีการประกาศไม่เหมาะสมเพราะว่าเรารู้อยู่แล้วว่าโปรแกรมจะมี result เพียง 2 ตัวดังนั้นสามารถกำหนดให้ result เป็น array 2 ช่องได้เลยไม่จำเป็นต้องกำหนด returnSize*/