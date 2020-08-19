#include <stdio.h>
#include <stdlib.h>
#define mile_feet 5280
#define km_feet 3282
float speed_fps(float);
float speed_mps(float);
int main()
{
    printf("Hello contestants\n");
    for(int i=0;i<4;i++)
    {
        float min,sec;
        printf("Enter time in minutes seconds-> ");scanf("%f %f",&min,&sec);
        float tt;tt=min*60+sec;
        printf("Speed in fps: %f f/s\n",speed_fps(tt));
        printf("Speed in mps: %f m/s\n",speed_mps(tt));
    }

    return 0;
}
float speed_fps(float x)
{
    return ((1*mile_feet)/x);
}
float speed_mps(float x)
{
    return ((1000*mile_feet)/(x*km_feet));
}
