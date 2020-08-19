/*5
2012B1TS000P,Alpha Beta,57
2012A7PS000P,Delta Gamma,57.5
2012B4PS000P,Lorem Ipsum,58.75
2012A3PS000P,Hulk Marvel,57.5
2012A7PS000P,Spiderman,59*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{char id[15];char name[100];float marks;int rank;}DATA;
void getdata(DATA [],int);
int main()
{

    int n;scanf("%d",&n);getchar();
    DATA arr[n];
    getdata(arr,n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {   DATA tmp;
            if(arr[i].marks<arr[j].marks){tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}
        }
    }
    arr[0].rank=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i].marks==arr[i-1].marks){arr[i].rank=arr[i-1].rank;}
        else{arr[i].rank=arr[i-1].rank+1;}
    }
    printf("ID\t\tNAME\t\tMarks\t\trank\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%s\t%f\t%d\n",arr[i].id,arr[i].name,arr[i].marks,arr[i].rank);
    }
    return 0;
}
void getdata(DATA brr[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%[^,]",brr[i].id);
        getchar();
        scanf("%[^,]",brr[i].name);
        getchar();
        scanf("%f",&brr[i].marks);
        getchar();
    }
}
