#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day=0;
    float paisa=0.01f,got=0.0f,given=0.00;
    for(;got<=given;)
    {
        day++;given+=100000.00f;
        got+=paisa;
        paisa*=2;
    }
    printf("Day of profit-> %d\nGiven-> %f; Got-> %f\n",day,given,got);
    return 0;
}
