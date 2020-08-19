#include <stdio.h>
#include <stdlib.h>
int fact(int);
int main()
{
    printf("ENTER THE NUMBER WHOSE FACTORIAL YOU WANT\n");
    int x;
    scanf("%i",&x);
    int b=fact(x);
    printf("Factorial: %d\n",b);
    return 0;
}
int fact(int n)
{
    if(n==1||n==0){return 1;}
    else {return n*fact(n-1);}
}
