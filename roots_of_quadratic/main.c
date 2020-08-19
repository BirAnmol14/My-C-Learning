#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("Real roots of Quadratic equation ax^2+bx+c=0\n");
    float a,b,c,d,r1,r2;
    printf("Enter a, b and c of the equation\n");
    scanf("%f %f %f",&a,&b,&c);
    d=b*b-4*a*c;
    switch(d>0)
    {
    //if d>0 true
    case 1: r1=(-b+sqrt(d))/(2*a);r2=(-b-sqrt(d))/(2*a);printf("root1: %f    root2: %f\n",r1,r2);break;
    //if d>0 false
    case 0:
            switch(d<0)
            {
                //if d<0 true
                case 1: printf("real roots do not exist\n");break;
                //if d<0 false i.e. d=0
                case 0: r1=(-b)/(2*a);printf("root1=root2= %f\n",r1);break;
            }break;
    }
    return 0;
}
