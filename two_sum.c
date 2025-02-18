/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize = malloc(sizeof(int) * 2);
    int i;

    i = 0;
    while(i < numsSize)
    {
        if(nums[i] + nums[i + 1] == target)
        {
            returnSize[0] = i;
            returnSize[1] = i + 1;
            break;
        }
        i++;
    }
    return (returnSize);
}

int main()
{
  int *returnSize = malloc(sizeof(int) * 2);
  int nums[2] = {3,3};
  int i = 0;

  while (i < 2)
  {
    printf("nums :%d\n", twoSum(nums, 4, 6, returnSize)[i]);
    i++;
  }
  
}
