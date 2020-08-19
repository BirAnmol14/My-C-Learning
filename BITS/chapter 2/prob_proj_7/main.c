#include <stdio.h>
#include <stdlib.h>
float taxc(int,float);
float af(int);
int main()
{
    printf("House Cost over 5 years\n");
    for (int i=0;i<3;i++)
    {
     int ic,afc;float tax;
       printf("Initial house cost: ");scanf("%d",&ic);
       printf("Annual Fuel cost: ");scanf("%d",&afc);
       printf("Tax Rate: ");scanf("%f",&tax);
       float tp;tp=(float)ic+af(afc)+taxc(ic,tax);
       printf("Total house price: %.2f\n",tp);
    }
    return 0;
}
float taxc(int x,float y)
{
    return 5*x*y;
}
float af(int x)
{
    return 5*x;
}
