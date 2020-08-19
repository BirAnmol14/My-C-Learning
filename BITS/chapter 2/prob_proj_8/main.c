#include <stdio.h>
#include <stdlib.h>
float acc(float,float,float);
int main()
{
    printf("Acceleration\n");
    float vi,vf,t;
    printf("Initial speed-> ");scanf("%f",&vi);
    printf("Final speed-> ");scanf("%f",&vf);
    printf("Time taken(min)-> ");scanf("%f",&t);
    printf("Acceleration: %f\n",acc(vi,vf,t));
    printf("Time taken to rest(vf=0): %f\n",(-vi/acc(vi,vf,t)));
    return 0;
}
float acc(float x,float y,float z)
{
    float  i;
    i=(y-x)/(60*z);
    return i;
}
