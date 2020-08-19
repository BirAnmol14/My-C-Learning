#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Compass\n");
    float deg;
    printf("Enter degrees: ");scanf("%f",&deg);
    if(deg>0&&deg<90){printf("Bearing reading: N->%.2f->E\n",deg);}
    else if(deg>90&&deg<180){printf("Bearing reading: S->%.2f->E\n",(180-deg));}
    else if(deg>180&&deg<270){printf("Bearing reading: S->%.2f->W\n",(deg-180));}
    else if(deg>270&&deg<360){printf("Bearing reading: N->%.2f->W\n",(360-deg));}
    else if(deg==0||deg==360){printf("Bearing reading N\n");}
    else if(deg==90){printf("Bearing reading E\n");}
    else if(deg==180){printf("Bearing reading S\n");}
    else if(deg==270){printf("Bearing reading W\n");}
    else{printf("Invalid compass degree input\n");}
    return 0;
}
