#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10000];
int main()
{
    printf("Write a String\n");
    scanf("%[^\n]%*c",s);
    int i=0;
    printf("Changed Case:\n");
    while(s[i]!='\0')
        {
            if (s[i]>='a'&&s[i]<='z'){s[i]=s[i]-'a'+'A';}else if(s[i]>='A'&&s[i]<='Z'){s[i]=s[i]+'a'-'A';}
            printf("%c",s[i]);
            i++;
        }
    printf("\nLength of word: %d\n",i);

    printf("\n");
    return 0;
}

