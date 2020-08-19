#include <stdio.h>
#include <stdlib.h>
void opselect(int);
void co(int,float);
void hcs(int,float);
void no(int,float);
void nmhcs(int,float);
int main()
{
    printf("Pollutants->\n");
    printf("(1) Carbon Monoxide\n");
    printf("(2) Hydrocarbons\n");
    printf("(3) Nitrogen oxides\n");
    printf("(4) Nomethane hydrcarbons\n");
    int op;printf("Enter pollutant number>> ");scanf("%d",&op);
    opselect(op);
    return 0;
}
void opselect(int op)
{
    float gpm;int or;
    printf("Enter number of grams emitted per mile>> ");scanf("%f",&gpm);
    printf("Enter odometer reading>> ");scanf("%d",&or);
    if(op==1){co(or,gpm);}
    else if(op==2){hcs(or,gpm);}
    else if(op==3){no(or,gpm);}
    else if(op==4){nmhcs(or,gpm);}
}
void co(int x,float y)
{
    if(x<=50000){if (y>3.4){printf("Emissions exceed permitted level of 3.4 grams/mile\n");}else {printf("emissions in limit\n");}}
    else if(x<=100000){if (y>4.2){printf("Emissions exceed permitted level of 4.2 grams/mile\n");}else {printf("emissions in limit\n");}}
}
void hcs(int x,float y)
{
    if(x<=50000){if (y>0.31){printf("Emissions exceed permitted level of 0.31 grams/mile\n");}else {printf("emissions in limit\n");}}
    else if(x<=100000){if (y>0.39){printf("Emissions exceed permitted level of 0.39 grams/mile\n");}else {printf("emissions in limit\n");}}
}
void no(int x,float y)
{
    if(x<=50000){if (y>0.4){printf("Emissions exceed permitted level of 0.4 grams/mile\n");}else {printf("emissions in limit\n");}}
    else if(x<=100000){if (y>0.5){printf("Emissions exceed permitted level of 0.5 grams/mile\n");}else {printf("emissions in limit\n");}}
}
void nmhcs(int x,float y)
{
    if(x<=50000){if (y>0.25){printf("Emissions exceed permitted level of 0.25 grams/mile\n");}else {printf("emissions in limit\n");}}
    else if(x<=100000){if (y>0.31){printf("Emissions exceed permitted level of 0.31 grams/mile\n");}else {printf("emissions in limit\n");}}
}
