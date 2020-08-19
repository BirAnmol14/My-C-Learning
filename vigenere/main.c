#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char s[100000];char key[100000];int x;int j=0;
int main()
{
    printf("Let's Encrypt\n");
    printf("Text for encryption: ");scanf("%[^\n]%*c",s);
    printf("Key(alphabetic word) for encryption: ");scanf("%[^\n]%*c",key);
    printf("\nENCRYPTED TEXT:\n");
    for(int i=0;i<strlen(s);i++)
        {if(isalpha(key[j]))
        {if (isupper(key[j])){x=key[j]-65;}else {x=key[j]-97;}
            if (isalpha(s[i]))
            {
                if (isupper(s[i]))
                    {
                        int n=s[i];
                         int m=((n-65+x)%26+65);
                        printf("%c",m);j++;if(j>=strlen(key)){j=(j%strlen(key));}
                    }
                else
                    {
                         int n=s[i];
                         int m=((n-97+x)%26+97);
                        printf("%c",m);j++;if(j>=strlen(key)){j=(j%strlen(key));}
                    }
            }
        else {printf("%c",s[i]);j=j+0;}
        }
        }
    printf("\n");
    return 0;
}

