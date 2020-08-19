#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char id[15];
    char campus[12];
    char email[100];
    char name[100];
}REC;
void populatedata(REC *);
void printdata(REC);
REC findcampandmail(REC);
int main()
{
    puts("**************UNIV NAME EST.******************");
    int n;
    scanf("%d",&n);getchar();
    REC arr[n];
    for(int i=0;i<n;i++)
    {populatedata(&arr[i]);}
    for(int i=0;i<n;i++)
    {arr[i]=findcampandmail(arr[i]);}
    puts("NAME\t\t\tID\t\t\tCAMPUS\t\t\tEMAIL ID");
    for(int i=0;i<n;i++)
    {printdata(arr[i]);}
    return 0;
}
void populatedata(REC * data)
{
    scanf("%[^,]",data->name);getchar();
    scanf("%[^\n]",data->id);getchar();
    return ;
}
void printdata(REC b)
{
    printf("%s\t\t%s\t\t%s\t\t%s\n",b.name,b.id,b.campus,b.email);
    return ;
}
REC findcampandmail(REC a)
{
    strcpy(a.email,"f");
    char yr[5];
    for(int i=0;i<4;i++)
    {
        yr[i]=(a.id)[i];
    }yr[4]='\0';
    strcat(a.email,yr);
    int y;
    y=atoi(yr);
    if(y>2016)
    {
        char tmp[5];
        for(int j=0;j<4;j++)
        {
            tmp[j]=(a.id)[j+8];
        }tmp[4]='\0';strcat(a.email,tmp);
        if((a.id)[12]=='P'){strcpy(a.campus,"PILANI   ");strcat(a.email,"@pilani.bits-pilani.ac.in");}
        else if((a.id)[12]=='G'){strcpy(a.campus,"GOA      ");strcat(a.email,"@pilani.bits-goa.ac.in");}
        else if((a.id)[12]=='H'){strcpy(a.campus,"HYDERABAD");strcat(a.email,"@pilani.bits-hyderabad.ac.in");}
    }else
     {
        char tmp[4];
        for(int j=0;j<3;j++)
        {
            tmp[j]=(a.id)[j+8];
        }tmp[3]='\0';strcat(a.email,tmp);
        if((a.id)[11]=='P'){strcpy(a.campus,"PILANI   ");strcat(a.email,"@pilani.bits-pilani.ac.in");}
        else if((a.id)[11]=='G'){strcpy(a.campus,"GOA      ");strcat(a.email,"@pilani.bits-goa.ac.in");}
        else if((a.id)[11]=='H'){strcpy(a.campus,"HYDERABAD");strcat(a.email,"@pilani.bits-hyderabad.ac.in");}
    }
    return a;
}
/*
Example
3
XYZ ABC,2018A7PS0000P
Tony Stark,2013A7PS000H
Pikachu Godzilla,3019A7PS0000G
*/
