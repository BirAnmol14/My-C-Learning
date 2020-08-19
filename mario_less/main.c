#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("hi\n");
    printf("enter a number\n");
    int a,b,c,d;
    scanf("%d",&a);
    if((a>0)&&(a<23))
    {
        for(b=0;b<a;b++)
        {
            for(c=a-b;c>0;c--)
            {
                printf(" ");
            }
            for(d=0;d<=b+1;d++)
            {
                printf("#");
            }
            printf("\n");
        }
    }else{main();}
    return 0;
}
