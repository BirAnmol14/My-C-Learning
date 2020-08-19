#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("HCF\nGive two numbers\n");
    int a,b;
    scanf("%d %d",&a,&b);
    int min,hcf;
    if (a<b){min=a;}else {min=b;}
    for (int i=1;i<=min;i++)
    {
        if (a%i==0&&b%i==0){hcf=i;}
    }printf("\nHCF: %d\n",hcf);
    return 0;
}
