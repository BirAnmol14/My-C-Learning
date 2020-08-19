#include <stdio.h>
#include <stdlib.h>
//the given exercise shows us that on many recursive calls stack can overflow
void p(int n);
void g();
void h();
void d();
int bits=0;
int main(){
	p(1);
	g();
	h();
	d();
}
void p(int n){
int pilani=1;
printf("Pilani: %u\n",&pilani);
printf("N: %d and address:%u\n",n,&n);
p(n+1);
g();
}
void g(){
int goa=2;
printf("Goa: %u\n",&goa);
h();
}
void h(){
int hyd=3;
printf("Hyd: %u\n",&hyd);
d();
}
void d(){
int dub=4;
printf("Dub: %u\n",&dub);p(1);
}

