#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
double gospel(int);
int main()
{
    printf("Approximate n! by Gosper formula\n");
    int n;
    printf("Enter the value n-> ");scanf("%d",&n);
    double a;a=gospel(n);
    printf("Approximate value of %d!: %lf\n",n,a);
    return 0;
}
double gospel(int x)
{
    double b,c,d,e;
    c=pow((double)x,(double)x);d=exp((double)-x);e=sqrt((2*((double)x)+(0.3333333))*PI);
    printf("%lf\t%lf\t%lf\n",c,d,e);
    b=c*d*e;
    return b;
}
