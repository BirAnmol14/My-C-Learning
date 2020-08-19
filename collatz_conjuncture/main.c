#include <stdio.h>
#include <stdlib.h>
int collatz(int);
int main()
{
    printf("Enter a number\n");
    int x,counter=0;
    scanf("%d",&x);
    int j;
    printf("Choose procedure to be followed:\n1 for non-recursive or 2 for recursive\n");
    scanf("%d",&j);
    if (j==1)
    {
    //without recursion
    while(x!=1)
    {
        if(x==1){exit(0);}
        else if(x%2==0){x=(x/2);counter++;}
        else if(x%2!=0){x=(3*x+1);counter++;}
    }
    printf("Steps taken to go back to 1: %d\n\n",counter);
    }
    if (j==2)
    {
        //with recursion
      printf("Steps taken to go back to 1: %d\n\n",collatz(x));
    }
    return 0;
}
int collatz(int x)
{
    if (x==1){return 0;}
    else if (x%2==0){return 1+collatz(x/2);}
    else {return 1+collatz(3*x+1);}
}
