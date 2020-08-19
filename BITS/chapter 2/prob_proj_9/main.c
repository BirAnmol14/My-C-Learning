#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926536
float tp(float,float,float,float);
float sa(float,float);
int main()
{
    printf("Open cylinder_COST CALCULATOR\n");
    float r,h,n,cost;
    printf("Enter radius-> ");scanf("%f",&r);
    printf("Enter height-> ");scanf("%f",&h);
    printf("Enter cost per sq. unit-> ");scanf("%f",&cost);
    printf("Enter quantity-> ");scanf("%f",&n);
    printf("\nTOTAL PRICE: %f\n",tp(r,h,cost,n));
    return 0;
}
float tp(float r,float h,float cost,float n)
{
    float surf,price;
    surf=sa(r,h);
    price=surf*cost*n;
    return price;
}
float sa(float r,float h)
{
    float area;
    area=PI*pow(r,2)+2*PI*r*h;
    return area;
}
