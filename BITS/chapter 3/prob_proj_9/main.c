#include <stdio.h>
#include <stdlib.h>
#define BASE 39.99
#define TAX 5.25/100
void receipt(float,float,float);
int main()
{
    printf("Bill calculator\n");
    float weekday_min,night_min,weekend_min;
    printf("Enter weekday calling minutes-> ");scanf("%f",&weekday_min);
    printf("Enter weekend calling minutes-> ");scanf("%f",&weekend_min);
    printf("Enter night(8 P.M. to 7 A.M.) calling minutes-> ");scanf("%f",&night_min);
    receipt(weekday_min,weekend_min,night_min);
    return 0;
}
void receipt(float wdm,float wem,float nm)
{
    float tc=wdm+wem+nm;float total,adm;
    printf("\n\n*****************************************\nRECEIPT\n");
    printf("Total calling minutes:             %.2f min\n",tc);
    printf("Weekday minutes used:              %.2f min\n",wdm);
    printf("Weekend minutes used:              %.2f min\n",wem);
    printf("Night minutes used:                %.2f min\n",nm);
    if (wdm>600.00)
    {
    adm=wdm-600;
    total=BASE+adm*0.40;
    printf("Base plan for 600 weekday minutes: $%.2f\n",BASE);
    printf("Rate of addition calling minutes:  0.40/min\n");
    printf("Additional calling minutes:        %.2f min\n",adm);
    printf("Cost of addition minutes used:     $%.2f\n",adm*0.40);
    printf("Total cost of weekday calling:     $%.2f\n",BASE+adm*0.40);
    printf("Total cost of weekend calling:     $0\n");
    printf("Total cost of night calling:       $0\n");
    printf("pre-tax total bill amount:         $%.2f\n",total);
    printf("Tax amount(5.25%%):                $%.2f\n",total*TAX);
    printf("post-tax total bill amount:        $%.2f\n",total+total*TAX);
    printf("FINAL ROUNDED OFF BILL->           $%.0f\n\n",total+total*TAX);
    printf("*****************************************\n");
    }
    else if(wdm<=600)
    {
    total=BASE;adm=0;
    printf("Base plan for 600 weekday minutes: $%.2f\n",BASE);
    printf("Total cost of weekday calling:     $%.2f\n",BASE+adm*0.40);
    printf("Total cost of weekend calling:     $0\n");
    printf("Total cost of night calling:       $0\n");
    printf("pre-tax total bill amount:         $%.2f\n",total);
    printf("Tax amount(5.25%%):                $%.2f\n",total*TAX);
    printf("post-tax total bill amount:        $%.2f\n",total+total*TAX);
    printf("FINAL ROUNDED OFF BILL->           $%.0f\n\n",total+total*TAX);
    printf("*****************************************\n");
    }
}
