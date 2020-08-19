#include <stdio.h>
#include <stdlib.h>

int main()
{
printf("Hello world!\n");
int m;printf("Number of rows- ");
scanf(" %d",&m);
int n[m];
int *p[m];
for(int i=0;i<m;i++)
{
printf("Number of elements: ");
scanf(" %d",&n[i]);
p[i]=malloc(n[i]*sizeof(int));
printf("Enter values: ");
for(int j=0;j<n[i];j++)
{
    scanf(" %d",&p[i][j]);
}
}
for(int i=0;i<m;i++)
{
for(int j=0;j<n[i];j++)
{
printf("%d\t",p[i][j]);
}putchar('\n');
}
for(int i=0;i<m;i++)
{
free(p[i]);
}
    return 0;
}
