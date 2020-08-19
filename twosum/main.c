#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numsSize,target;
   printf("Enter the size of array\n");
    scanf("%d", &numsSize);
    printf("Enter the target\n");
    scanf("%d", &target);
    int nums[numsSize];
    printf("Enter elements of array\n");
    for (int k=0;k<numsSize;k++)
    {
        scanf("%d",&nums[k]);
    }
    for(int i=0;i<numsSize;i++)
    {
        for (int j=0;j<i;j++)
        {
            if(nums[i]+nums[j]==target){printf("index of elements that add to target are %d %d",j,i);exit(0);}else {continue;}
        }
    }printf("Not possible!!\n");
    return 0;
}
