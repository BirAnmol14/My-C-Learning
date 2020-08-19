#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rows 5
#define cols 150
void sort(char arr[][cols]);
int main()
{   printf("Hello, names please\n");
    char name[rows][cols];
    for(int i=0;i<rows;i++)
     {scanf(" %[^\n]",name[i]);}
    sort(name);
    for(int i=0;i<rows;i++)
    {
        puts(name[i]);
    }
    return 0;
}
void sort(char arr[][cols])
{ char tmp[cols];
    for (int i=0;i<rows-1;i++)
    {
        for(int j=i+1;j<rows;j++)
        {
            if(strcmp(arr[i],arr[j])>0)
            {
                strcpy(tmp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],tmp);
            }
        }
    }
}
