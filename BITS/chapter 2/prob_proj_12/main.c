#include <stdio.h>
#include <stdlib.h>
double sosa(float);
int main()
{
    float fah;
    printf("SPEED OF SOUND in air\n");
    printf("Temperature of air-> ");scanf("%f",&fah);
    printf("SPEED OF SOUND in air at temp. %.3f: %.5lf\n",fah,sosa(fah));
    return 0;
}
double sosa(float t)
{
    double a,b;
    b=(5*(double)t+297)/247;
    a=1086*sqrt(b);
    return a;
}
