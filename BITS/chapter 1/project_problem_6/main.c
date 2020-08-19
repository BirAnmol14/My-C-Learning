#include <stdio.h>
#include <stdlib.h>

int main()
{
    char grade;float min_avg,curr_avg,pcg,marks;
    printf("Enter desired grade> ");scanf(" %c",&grade);
    printf("Enter minimum average required> ");scanf("%f",&min_avg);
    printf("Enter current average required> ");scanf("%f",&curr_avg);
    printf("Enter how much the final counts\nas a percentage of the final course grade> ");scanf("%f",&pcg);
    float a,b;a=pcg/100;b=(100-pcg)/100;
    marks=(min_avg-b*curr_avg)/a;
    printf("You need a score of %.2f on the final to get a %c\n",marks,grade);
    return 0;
}
