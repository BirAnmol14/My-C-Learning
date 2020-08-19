#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N, r;
    printf("Please enter a number in decimal form: \n");
    scanf("%d", &N);
    printf("Please enter the desired base between 0 to 10: ");
    scanf("%d", &r);
    while(r<1||r>9){printf("Please enter the desired base between 0 to 10: ");
    scanf("%d", &r);}
    if(N==0){printf("UNSIGNED: \n0\n");exit(0);}
    int arr[10000];int count=0;
while(N!=0)
{           (arr[count])=(N%r);
            N=(N/r);
            count++;
}
printf("UNSIGNED:\n");
       for (int i=count-1;i>=0;i--)
       {
           printf("%d",arr[i]);
       }

    return 0;
}
