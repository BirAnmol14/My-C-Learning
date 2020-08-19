#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Prime Test\nEnter a number >0\n");
    int n;
    scanf("%d",&n);
    if (n<=0){printf("Wrong input, try again\n");main();}
    else if(n==1){printf("Neither prime nor composite\n");}
    else if(n==2){printf("Prime Number\n");}
    else
    {
        for(int i=2;i<=n-1;i++)
        {
            if (n%i==0){printf("Composite Number\n");exit(0);}
            else{continue;}
        }
    printf("Number is prime\n");}
    return 0;
}
