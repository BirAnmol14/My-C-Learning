#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strlast(char[],char[]);
int main()
{
    char mystr[1000],anchor[5];
    scanf("%[^\n]",mystr);getchar();
    scanf("%[^\n]",anchor);getchar();
    char * start=strstr(mystr,anchor);
    char *end=strlast(mystr,anchor);
    char *p=mystr;
    char newstr[1000];int i=0;
    for(;p<start;p++,i++)
    {
        newstr[i]=*(p);
    }
    p=end+strlen(anchor);
    for(;*p!='\0';p++,i++)
    {
        newstr[i]=*(p);
    }
    newstr[i]='\0';
    printf("\n%s\n",newstr);
    return 0;
}
char * strlast(char mystr[],char anchor[])
{
    char *start=strstr(mystr,anchor),*prev;prev=start;
    while(start)
    {
        prev=start;
        start=strstr(start+strlen(anchor),anchor);
    }
    return prev;
}
