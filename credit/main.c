#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int csum(long long);
char c[16];
int main()
{
    long long cno;
    printf("WELCOME TO CREDIT CARD VERIFIER\n");
    do {printf("Please enter your card number\n"); scanf("%s",c);cno=atoll(c);}
    while (cno<=0);
    if(csum(cno)%10==0)
        {
            if((strlen(c)==15)&&(c[0]=='3')&&(c[1]=='4'||'7')){printf("\nCARD IS VALID\nCompany:AMERICAN EXPRESS\n");}
            else if((strlen(c)==13||16)&&(c[0]=='4')){printf("\nCARD IS VALID\nCompany:VISA CARD\n");}
            else if((strlen(c)==16)&&(c[0]=='5')&&(c[1]=='1'||'2'||'3'||'4'||'5')){printf("\nCARD IS VALID\nCompany:MASTER CARD\n");}
            else{printf("Card is invalid\n");}
        }
    else{printf("Card is invalid\n");}
    char b;
    printf("\nDo you want to repeat(y/n)\n");
    scanf(" %c",&b);
    if (b=='y'){main();}else if (b=='n'){exit(0);}
    return 0;
}
int csum(long long x)
{
    long long so=0,se=0;
    long long rem,quo,sum;
    for(int i=0;i<strlen(c);i++)
    {
        if(i%2==0){quo=x/10;rem=x%10;se=se+rem;}
        else if((i%2)!=0){quo=x/10;rem=2*(x%10);if(rem>9){so=so+(rem/10)+(rem%10);}else{so=so+rem;}}
        x=quo;
    }
    sum=so+se;
    return (sum);
}
*/
int main()
{
    char ch,str[50];int count = 0;
    scanf("%s",str);scanf(" %c",&ch);
    for(int i=0;i<strlen(str);i++)
    {
        if(ch==str[i]){count++;}
    }
    printf("\n%d\n",count);
    return 0;
}
