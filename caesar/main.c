#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char s[100000];int key;
int main()
{
    printf("Let's Encrypt\n");
    printf("Text for encryption: ");scanf("%[^\n]%*c",s);
    printf("Key(numeric) for encryption: ");scanf("%d",&key);
    printf("\nENCRYPTED TEXT:\n");
    for(int i=0,j=strlen(s);i<j;i++)
    {
        if (isalpha(s[i]))
            {
                if (isupper(s[i]))
                    {
                        int n=s[i];
                         int m=((n-65+key)%26+65);
                        printf("%c",m);
                    }
                else
                    {
                         int n=s[i];
                         int m=((n-97+key)%26+97);
                        printf("%c",m);
                    }
            }
        else printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}
