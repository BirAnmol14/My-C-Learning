#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    printf("Hi!\n");
    printf("Please enter the height of the staircase\n");
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
            printf("    ");
            for(d=0;d<=b+1;d++)
            {
                printf("#");
            }
            for(c=a-b;c>0;c--)
            {
                printf(" ");

            }    printf("\n");    }
    }else{main();}
    return 0;
}
