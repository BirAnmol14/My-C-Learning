#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
                int num;
                int den;
              }FRAC;
FRAC getdata();
FRAC reduce(FRAC);
int hcf(int,int);
int lcm(int,int);
FRAC addfrac(FRAC,FRAC);
int main()
{
    FRAC f1,f2,f3;
    //getting input
    f1=getdata();f2=getdata();
    if(f1.num!=0&&f2.num!=0){printf("Fraction 1-> %d/%d\nFraction 2-> %d/%d\n",f1.num,f1.den,f2.num,f2.den);}
    else if(f1.num!=0&&f2.num==0)
    {
        printf("Fraction 1-> %d/%d\nFraction 2-> 0\n",f1.num,f1.den);
    } else if(f1.num==0&&f2.num!=0)
    {
        printf("Fraction 1-> 0\nFraction 2-> %d/%d\n",f2.num,f2.den);
    }
    else
    {
        printf("Fraction 1-> 0\nFraction 2-> 0\n");
    }
    //reducing now
    f1=reduce(f1);f2=reduce(f2);
    puts("After reduction");
    if(f1.num!=0&&f2.num!=0){printf("Fraction 1-> %d/%d\nFraction 2-> %d/%d\n",f1.num,f1.den,f2.num,f2.den);}
    else if(f1.num!=0&&f2.num==0)
    {
        printf("Fraction 1-> %d/%d\nFraction 2-> 0\n",f1.num,f1.den);
    } else if(f1.num==0&&f2.num!=0)
    {
        printf("Fraction 1-> 0\nFraction 2-> %d/%d\n",f2.num,f2.den);
    }
    else
    {
        printf("Fraction 1-> 0\nFraction 2-> 0\n");
    }
    //adding now
    f3=addfrac(f1,f2);
    if(f3.num==0){printf("after sum-> 0\n");}
    else{printf("after sum-> %d/%d\n",f3.num,f3.den);}
    //one final reduction
    f3=reduce(f3);
    puts("Sum after reduction");
    if(f3.num==0){printf("after sum-> 0\n");}
    else{printf("after sum-> %d/%d\n",f3.num,f3.den);}
    return 0;
}
FRAC getdata()
{
    FRAC f;
    printf("Numerator: ");scanf("%d",&f.num);
    printf("Denominator: ");scanf("%d",&f.den);if(f.den==0){printf("Error!!\n");exit(0);}
    if(f.num>0&&f.den>0)
    {return f;}
    else if(f.num>0&&f.den<0)
    {f.num=-1*f.num;f.den=-1*f.den;return f;}
    else if(f.num<0&&f.den>0){return f;}
    else if(f.num<0&&f.den<0){f.num=-1*f.num;f.den=-1*f.den;return f;}
}
FRAC reduce(FRAC f)
{
    if(f.num!=0)
    {
    int h=hcf(abs(f.num),abs(f.den));
    f.num=f.num/h;
    f.den=f.den/h;
    return f;
    }
    else {return f;}
}
int hcf(int x,int y)
{ int tmp;
    if(x>=y)
    {
        while(1)
        {
        if(x%y==0){return y;}
        else{tmp=x;x=y;y=(tmp%y);}
        }
    }
    else
    {
        while(1)
        {if(y%x==0){return x;}
        else{tmp=y;y=x;x=(tmp%x);}
        }
    }
}
int lcm(int x,int y)
{
    if(x%y==0){return x;}
    else if(y%x==0){return y;}
    else
    { int i=2;
        while(1)
        {
            if((x*i)%y==0){return x*i;}
            else {i++;}
        }
    }
}
FRAC addfrac(FRAC f1,FRAC f2)
{
    if(f1.num==0){return f2;}
    else if(f2.num==0){return f1;}
    else{
    FRAC f;
    int l=lcm(abs(f1.den),abs(f2.den));
    int n;
    n=(l/f1.den)*(f1.num)+(l/f2.den)*(f2.num);
    f.num=n;f.den=l;
    return(f);
    }
}
