#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Hello guys!\n");
    printf("Please enter your full name\n");
    char name[100];
    scanf("%[^\n]%*c",name);
    char initials[4];
    int j=0;
    for (int i=0;i<strlen(name);i++)
    {
        if (isupper(name[i]))
        {
            initials[j]=name[i];
            j++;
        }
    }initials[j]='\0';
    printf("%s\n",initials);
    return 0;
}
