#include <stdio.h>
#include <stdlib.h>
#define PAY 0.35
int main()
{
    float ior,eor,trv,reimb;
    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
    printf("Enter beginning odometer reading=> ");scanf("%f",&ior);
    printf("Enter ending odometer reading=> ");scanf("%f",&eor);
    trv=eor-ior;
    printf("You traveled %.1f miles.\tAt $0.35 per mile,\n",trv);
    reimb=PAY*trv;
    printf("your reimbursement is $%.2f\n",reimb);
    return 0;
}
