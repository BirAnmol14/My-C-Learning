#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("N-> ");int N;scanf("%d",&N);
    double num,sum=0;
    for(int a=0;a<=N;a++)
    { double den=1;
        num=3+2*a;
        for(int j=0;j<a;j++)
        {
            den*=-2;
        }
        sum+=(num/den);
    }
    printf("%lf\n",sum);
    return 0;
}
