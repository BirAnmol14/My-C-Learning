#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ALL PRIME\nENTER THE NUMBER OF PRIME NUMBERS YOU WANT\n");
    int n,i = 3, count, c;

    scanf("%d",&n);
   if(n >= 1)
    {
        printf("\n\nFirst %d prime numbers are :  ", n);
        printf("2 ");

    for(count = 2; count <= n; i++)
    {

        for(c = 2; c < i; c++)
        {
            if(i%c == 0)
                break;
        }

        if(c == i)
        {
            printf("%d ", i);
            count++;
        }

    }}
    else
    {
        printf("WRONG INPUT\n try again\n");
        main();
    }
    return 0;
}
