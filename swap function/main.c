#include <stdio.h>
#include <stdlib.h>
int swap(int*,int*);
int main()
{
    int x,y;
    printf("Enter 1st number\n");
    scanf("%d",&x);
    printf("Enter 2nd number\n");
    scanf("%d",&y);
    printf("x is %d and y is %d\n",x,y);
    swap(&x,&y);printf("After Swap\n");
    printf("x is %d and y is %d\n",x,y);
    return 0;
}
int swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
    return *a,*b;
}
