#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k=1,t=1;
    printf("n-> ");scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if (t/10!=0){t=t%10;}
        for(int j=(n-i-1);j>0;j--)
        {
            putchar(' ');
        }
        for(int j=i;j>=1;j--)
        {if((k-j)/10==0){printf("%d",k-j);}else {int h=(k-j)%10;printf("%d",h);}}
        printf("%d",t);
        for(int j=1;j<=i;j++)
        {if((k-j)/10==0){printf("%d",k-j);}else {int h=(k-j)%10;printf("%d",h);}}
        for(int j=(n-i-1);j>0;j--)
        {
            putchar(' ');
        }
        k+=2;t+=2;
        printf("\n");
    }
    return 0;
}
