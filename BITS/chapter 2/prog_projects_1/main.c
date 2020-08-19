#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("WELCOME\n");
    float pp,dp,ai,i,n,bp,mp;
    printf("purchase price of car: ");scanf("%f",&pp);
    printf("down payment: ");scanf("%f",&dp);bp=pp-dp;
    printf("Annual interest rate: ");scanf("%f",&ai);i=ai/1200; // ai/1200 converting percentage in to normal fraction
    printf("Number of monthly payments(36/48/60): ");scanf("%f",&n);
    printf("BORROWED AMMOUNT-> $%.2f\n",bp);
    mp=((i*bp)/(1-pow((1+i),-n)));
    printf("Monthly Payable AMMOUNT-> $%.2f\n",mp);
    return 0;
}
