#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,c=0;
    int x=0,y=1,z;
    printf("Enter number of terms of series required\n");
    scanf("%d",&t);
    if (t>0){
    printf("Sequence: ");
    while(c<t){printf("%d ",x);z=x+y;y=x;x=z;c++;}}else {main();}
    return 0;
}
