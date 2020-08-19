#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("WELCOME!!!\ncheck leap year or not\n");
    printf("Enter the year\n");int yr;
    scanf("%d",&yr);
    if(yr%4==0)
    {
        if (yr%100==0)
        {
            if (yr%400==0)
            {
                printf("It is a leap year\n");
            }else {printf("It is not a leap year\n");}
        }else {printf("It is a leap year\n");}
    }else {printf("It is not a leap year\n");}
    char c;printf("\nWanna Repeat(y/n)\n");
    scanf(" %c",&c);
    switch(c)
    {
        case 'y':
        case 'Y': main();break;
        case 'N':
        case 'n': exit(0);
    }
    return 0;
}
