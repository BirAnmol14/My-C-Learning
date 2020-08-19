#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("CONVERT TO ASCII\n");
    char word[1000];
    scanf("%[^\n]%*c",word);
    printf("\nTHE ASCII VALUES ARE:\n");
    for (int i=0;word[i]!='\0';i++)
    {
        printf("%c        %d\n",word[i],word[i]);
    }
    return 0;
}
