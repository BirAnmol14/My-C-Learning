#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Bill\n");
    char t;float tb;
    printf("Are you a music teacher(y/n): ");scanf(" %c",&t);
    printf("Total purchases:                   $");scanf("%f",&tb);
    if (t=='y'||t=='Y')
    {
    if (tb>=100)
    {
    printf("Teacher's Discount (12%%):         $%.2f\n",(12*tb/100));
    tb=tb-(12*tb/100);
    }
    else
    {
    printf("Teacher's Discount (10%%):         $%.2f\n",(10*tb/100));
    tb=tb-(10*tb/100);
    }
    printf("Discounted total:                 $%.2f\n",tb);
    printf("Sales tax (5%%):                  $%.2f\n",(5*tb/100));
    printf("Total:                            $%.2f\n",(tb+(tb*5)/100));
    }
    else
    {
    printf("Sales tax (5%%):                  $%.2f\n",(5*tb/100));
    printf("Total:                            $%.2f\n",(tb+(tb*5)/100));
    }
    return 0;
}
