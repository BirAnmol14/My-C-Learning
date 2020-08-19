#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Enter 2 integers> ");
    scanf("%d%d",&m,&n);
    m=m+5;n=3*n;
    printf("\nm=%d\tn=%d",m,n);
    return 0;
}
