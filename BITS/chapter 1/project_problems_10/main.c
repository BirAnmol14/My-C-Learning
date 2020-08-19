#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Perpendicular bisector\n");
    float x1,x2,x3,y1,y2,y3,m1,m2,c;
    printf("Enter coordinates of point 1 in x y format-> ");scanf("%f %f",&x1,&y1);
    printf("Enter coordinates of point 2 in x y format-> ");scanf("%f %f",&x2,&y2);
    x3=0.5*(x1+x2);y3=0.5*(y1+y2);
    if (((y2-y1)==0)&&((x2-x1)!=0)){printf("\nEquation of perpendicular bisector is X=%.2f",x3);}
    else if (((y2-y1)!=0)&&((x2-x1)==0)){printf("\nEquation of perpendicular bisector is Y=%.2f",y3);}
    else if (((y2-y1)!=0)&&((x2-x1)!=0))
    {
        m1=(y2-y1)/(x2-x1);
        m2=(-1/m1);
        c=y3-m2*x3;
        printf("\nEquation of perpendicular bisector is Y=%.2fX+%.2f\n",m2,c);
    }else {printf("no perpendicular bisector possible\n");}
    return 0;
}
