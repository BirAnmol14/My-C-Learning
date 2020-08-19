#include <stdio.h>
#include <stdlib.h>
float cel(float);
float fah(float);
int main()
{
    float depth;
    printf("TEMP AT DEPTH\n");
    printf("Depth below earth's surface-> ");scanf("%f",&depth);
    printf("Temperature below earth's surface(C): %f\n",cel(depth));
    printf("Temperature below earth's surface(F): %f\n",fah(cel(depth)));
    return 0;
}
float cel(float d)
{
    float k=(10*d+20);
    return k;
}
float fah(float a)
{
    float b;b=1.8*a+32;
    return b;
}
