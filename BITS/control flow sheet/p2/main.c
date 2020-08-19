#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;do{printf("n(odd number)-> ");scanf("%d",&n);}while(n%2==0);
    for(int i=0;i<(n/2+1);i++)
    {
        printf("*");
         for (int j=0;j<=(i-2);j++)
        {
            printf(" ");
        }
        if(i-1>=0){printf("*");}
        for (int j=0;j<(n-2-2*i);j++)
        {
            printf(" ");
        }
        if(i<n/2)
        {if(i-1>=0){printf("*");}}
         for (int j=0;j<=(i-2);j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(int i=(n/2);i>0;i--)
    {
        printf("*");
        for(int j=0;j<i-2;j++)
        {
            printf(" ");
        }
        if(i-1>0){printf("*");}
        for(int j=0;j<(1+2*((n/2)-i));j++)
        {
            printf(" ");
        }
        if(i-1>0){printf("*");}
        for(int j=0;j<i-2;j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}
