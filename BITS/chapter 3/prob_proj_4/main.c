#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("GAS CONTENTS\n");
    char c;
    printf("Enter first letter of color of gas observed: ");scanf(" %c",&c);
    switch (c)
    {
    case 'o':
    case 'O':
        printf("Gas is-> Ammonia\n");break;
    case 'B':
    case 'b':
        printf("Gas is-> Carbon monoxide\n");break;
    case 'y':
    case 'Y':
        printf("Gas is-> Hydrogen\n");break;
    case 'G':
    case 'g':
        printf("Gas is-> Oxygen\n");break;
    default: printf("Gas unknown\n");break;
    }
    return 0;
}
