#include <stdio.h>
#include <stdlib.h>
int lepo(int);
int main()
{
    int mth,yr,day,dday=0;
    printf("Enter Date in dd mm yyyy format-> ");scanf("%d %d %d",&day,&mth,&yr);
    if(day<32&&mth<13&&mth>0&&day>0&&yr>0)
    {
    int monthdl[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int monthdnl[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i=lepo(yr);
    if(i==1)
    {
        for (int j=0;j<mth-1;j++)
        {
            dday=dday+monthdl[j];
        }
        dday=dday+day;
        printf("Day Number: %d",dday);
    }
    else if(i==0)
    {
        for (int j=0;j<mth-1;j++)
        {
            dday=dday+monthdnl[j];
        }
        dday=dday+day;
        printf("Day Number: %d",dday);
    }
    }
    else {printf("Error! Wrong input\n\n");main();}
    return 0;
}
int lepo(int x)
{
    if(x%4==0)
    {
        if (x%100==0)
        {
            if (x%400==0)
            {
                return 1;
            }else {return 0;}
        }else {return 1;}
    }else {return 0;}
}
