#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("Juggler Sequence\n");
    printf("Enter the n: ");int i;scanf("%d",&i);
    printf("Juggler An is: %d\n",jug_n(i));
    jug_seq(i);
    return 0;
}
int jug_n(int n){
    if(n==0){
        return 3;
    }
    if(n>0){
            int val=jug_n(n-1);
        if(val%2==0){
            return (int)sqrt(val);
        }else{
            return (int)pow(val,1.5);
        }
    }
}
void jug_seq(int n){
    if(n==0){
        printf("3\t");return;
    }
    if(n>0){
            jug_seq(n-1);
            printf("%d\t",jug_n(n));
    }
}
