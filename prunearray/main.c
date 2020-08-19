#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
int prunearray(int *,int);
int main()
{
    int n;
    printf("NUMBER of numbers you want to enter-> ");scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count=prunearray(arr,n);
    printf("number of non-zero elements-> %d\n",count);
    printf("pruned array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
int prunearray(int *ptr,int n)
{
 int c=0;
 for(int i=0;i<n;i++)
 {
     if(*(ptr+i)){c++;}
 }
 for(;1;)
 { int flag=0;
     for(int j=0;j<n-1;j++)
 {
     if(ptr[j]==0&&ptr[j+1]!=0){swap((ptr+j),(ptr+j+1));flag++;}
 }
 if(flag==0){break;}
 }
return c;
}
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
