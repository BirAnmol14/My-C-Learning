#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("LCM\n");
    printf("Enter two numbers\n");
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    int max,min;
    if (a>b){max=a;min=b;}else{max=b;min=a;}
    for(int i=1;i>0;i++)
    {
        int pro=max*i,div=pro%min;
        if (div==0){printf("LCM: %lld\n",pro);exit(0);}
    }
    return 0;
}
