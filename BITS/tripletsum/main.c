#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,m;
   scanf("%d",&n);
   scanf("%d",&m);
   int arr[n];
   for(int i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   for(int i=0;i<n-2;i++)
   {
       for(int j=i+1;i<n-1;i++)
       {
           for(int k=j+1;k<n;k++)
           {
               if(arr[i]+arr[j]+arr[k]==m){printf("%d+%d+%d=%d\n",arr[i],arr[j],arr[k],m);return 1;}
           }
       }
   }
    return 0;
}
