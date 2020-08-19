#include <stdio.h>
#include <stdlib.h>
 int m,n,s1,s2,s3;
int main()
{
    printf("Generating Pythagorean Triplet\n");
    printf("(by using two numbers)\n");
    prog:
    printf("Enter number 1-> ");scanf("%d",&m);
    printf("Enter number 2-> ");scanf("%d",&n);
    if(m>n){s1=m*m-n*n;s2=2*m*n;s3=m*m+n*n;printf("Pythagorean triplet: %d, %d, %d\n",s1,s2,s3);}
    else if(m<n){s1=n*n-m*m;s2=2*m*n;s3=m*m+n*n;printf("Pythagorean triplet: %d, %d, %d\n",s1,s2,s3);}
    else if (m==n){printf("Unable to generate Pythagorean triplet\nEnter 2 different numbers\n\n");goto prog;}
    return 0;
}
