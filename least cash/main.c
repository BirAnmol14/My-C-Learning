#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,note[9]={2000,500,200,100,50,20,10,5,1},nc[9],nd=0;
    printf("Hi, Welcome to least cash ATM\n");
    printf("We have denominations of 2000,500,200,100,50,20,10,5 and 1\n");
    printf("Enter the amount you want\n");
    scanf("%d",&a);
    for(int i=0;i<9;i++)
    {
        nc[i]=a/note[i];
        a=a-(nc[i]*note[i]);
        nd=nd+nc[i];
        printf("%d : %d\n",note[i],nc[i]);
    }
    printf("\nTotal notes dispensed=%d\n",nd);
    return 0;
}
