#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int id;
    int age;
    char name[100];
}DATA;
void sortd(DATA * [],int );
int main()
{
    int n;
    printf("*************BITS PILANI************\nNo. of students? ");scanf(" %d",&n);
    DATA *p[n];puts("Give data:");
    for(int i=0;i<n;i++)
    {
        printf("Student %d\n",i+1);
        p[i]=malloc(1*sizeof(DATA));
        printf("Id no.\t");scanf(" %d",&(p[i]->id));
        printf("Age\t");scanf(" %d",&(p[i]->age));getchar();
        printf("Name\t");scanf("%[^\n]",(p[i]->name));
    }
    sortd(p,n);
    printf("SNO.\tID NO.\tAGE\tNAME\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%s\t",i+1,p[i]->id,p[i]->age,p[i]->name);
        free(p[i]);
        putchar('\n');
    }
    return 0;
}
void sortd(DATA * p[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            DATA * tmp;
            if(strcmp(p[i]->name,p[j]->name)>0){tmp=p[i];p[i]=p[j];p[j]=tmp;}
        }
    }
}

