#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v,m,rate;
    printf("Volume to be infused (ml) => ");scanf("%d",&v);
    printf("Minutes over which to infuse => ");scanf("%d",&m);
    rate=v/m*60;
    printf("\n\nVTBI: %d ml\n",v);
    printf("RATE: %d ml/hr\n",rate);
    return 0;
}
