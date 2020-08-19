#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Fahrenheit to Celsius\n");
    int f;double c;
    printf("Enter temp in Fahrenheit-> ");scanf("%d",&f);
    c=((double)f-32)*5/9;
    printf("Temp in Celsius: %lf",c);
    return 0;
}
