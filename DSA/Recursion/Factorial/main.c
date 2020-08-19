#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int val=fact(n);
    if(val!=-1){
    printf("%d! = %d\n",n,val);
    }
    else{
        printf("Invalid\n");
    }
    return 0;
}
int fact(int n){
    if(n==0){
        return 1;
    }
    else if(n>=1){
        return n*fact(n-1);
    }
    return -1;
}
