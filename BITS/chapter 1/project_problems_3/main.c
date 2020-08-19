#include <stdio.h>
#include <stdlib.h>

int main()
{
    float hrs,min;
    float t,T;
    printf("Temperature in a freezer\n");
    printf("Enter in time elapsed after power failure in hours and minutes-> ");
    scanf("%f %f",&hrs,&min);
    t=hrs+(min/60);
    T=((4*t*t)/(t+2))-20;
    printf("CURRET TEMPERATURE IN FREEZER:%f *C",T);
    return 0;
}
