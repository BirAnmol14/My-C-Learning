#include <stdio.h>
#include <stdlib.h>
float pop(int);
int main()
{
    printf("GOTHAM POPULATION\n");
    int yr,dec;
    printf("Enter year after 1990-> ");scanf("%d",&yr);
    dec=(yr-1990)%10;
    printf("POPULATION OF GOTHAM CITY FOR YEAR %d (in thousands):\n %.3f\n",(yr-dec),pop(yr));
    return 0;
}
float pop(int x)
{
    int y;
    y=(x-1990);
    float m;
    m=52.966+2.184*(float)y;
    return m;
}
