#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float weight,height,bmi;
void bmi_check(float);
int main()
{
    printf("BMI CALCULAT OR AND ANALYSER\n");
    printf("Which system of measurement do you use:\n1. Kg/m^2\n2. Pound/inch^2\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter height in meters: ");scanf("%f",&height);
        printf("Enter weight in kilogram: ");scanf("%f",&weight);
        bmi=(weight)/(height*height);
        bmi_check(bmi);
    }
    else if(choice==2)
    {
        printf("Enter height in inch: ");scanf("%f",&height);
        printf("Enter weight in pounds: ");scanf("%f",&weight);
        bmi=(703*weight)/(height*height);
        bmi_check(bmi);
    }
    else{printf("Error! you chose the wrong option\n");}
    return 0;
}
void bmi_check(float x)
{
    if(x<18.5){printf("\nYOU ARE:\nUnderweight\n");}
    else if(x<25){printf("\nYOU ARE:\nNormal\n");}
    else if(x<30){printf("\nYOU ARE:\nOverweight\n");}
    else {printf("\nYOU ARE:\nOverweight\n");}
}
