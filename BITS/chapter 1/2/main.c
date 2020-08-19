#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int main()
{
    printf("Enter radius of circle\n");
    double r;
    scanf("%lf",&r);
    printf("Area: %lf\n",PI*r*r);
    return 0;
}
