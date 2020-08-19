#include <stdio.h>
#include <stdlib.h>
#define EFFICIENCY 0.90
#define g 9.80
#define den 1000
int main()
{
    double w,m,h,v;
    printf("Power of hydroelectric dam\n");
    printf("Enter height of dam  ");scanf("%lf",&h);
    printf("Enter volume(in cubic meters) flowing from dam per second  ");scanf("%lf",&v);
    m=den*v;
    w=(m*g*h*EFFICIENCY)/(1e6);
    printf("\n\n***POWER PRODUCED BY DAM=%lf MW***\n\n",w);
    return 0;
}
