#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    printf("Hello guys\nGive me a sentence\n");
    char sent[1000];scanf("%[^\n]",sent);
    char word[50];puts("Give me a word: ");getchar();
    scanf("%[^\n]",word);
    char *p=sent;char *q;int count=0;
    q=strstr(sent,word);
    while(q)
    {if(q){count++;}
        q=strstr(q+1,word);
    }
    printf("%d",count);
    return 0;
}
