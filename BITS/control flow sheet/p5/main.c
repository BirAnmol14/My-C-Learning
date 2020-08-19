#include <stdio.h>
#include <stdlib.h>
#define MAX_ATT 1
int main()
{
    int n,count=0;
    do
    {
       printf("for English, please press 1;for Hindi, please press 2;for Marwari,\nplease press 3;for Tamil, please press 4;for Telugu, please press 5;");
       putchar('\n');scanf("%d",&n);
       switch(n)
       {   case 1: printf("Eng\n");count=MAX_ATT;break;
           case 2: printf("Hin\n");count=MAX_ATT;break;
           case 3: printf("Mar\n");count=MAX_ATT;break;
           case 4: printf("Tam\n");count=MAX_ATT;break;
           case 5: printf("Tel\n");count=MAX_ATT;break;
           default: count++;if(count<MAX_ATT){printf("Sorry, you have entered an invalid option. Please try again.\n");}else{printf("maximum attempts exceeded\n");};break;
       }
    }while(count<MAX_ATT);
    return 0;
}
