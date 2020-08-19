#include <stdio.h>
#include <stdlib.h>
void d2b(int n);
int main()
{
    printf("Decimal To Binary!\n");
    printf("Enter Decimal Number: ");
    int num;scanf("%d",&num);
    d2b(num);
    return 0;
}
void d2b(int n){
    if(n==0){
        printf("0");
        return;
    }
    if(n==1){
        printf("1");
        return;
    }
    if(n>1){
        d2b(n/2);
        printf("%d",n%2);
    }
}
