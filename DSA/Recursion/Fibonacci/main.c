#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Fibonacci Series\n");
    printf("Enter Number of Numbers in series: ");
    int n;scanf("%d",&n);
    int i=0;
    for(;i<n-1;i++){
        printf("%d,\t",fib(i));
    }
    printf("%d\n",fib(i));
    return 0;
}
int fib(int i){
    if(i==0){
        return 0;
    }
    if(i==1){
        return 1;
    }
    if(i>1){
        return fib(i-1)+fib(i-2);
    }
    return -1;
}
