#include "exer1.h"
#include <sys/time.h>
#include <math.h>
#define start 10
int * base=0; int * top=0;
int count=0; 
void test(int);
void test_up(int);
int main(){
	int t=size;base=&t;
	for(int i=start;i>=1;i--){
		test(i);
	}
	for(int i=2;i<=start;i++){
		test_up(i);
	}
	puts("Output produced in output_ms_rec.txt");
}
void  merge_sort(stu_rec * rec,int sz){
	if(sz==1){
		if(!count){
		FILE * o=fopen("output_ms_rec.txt","a+");
		top=&sz;
		fprintf(o,"Stack space used: %d\n",abs(top-base)*4);
		fclose(o);count++;
		}
		return;
	}
	stu_rec result[sz];
	merge_sort(rec,sz/2);
	merge_sort(&rec[sz/2],sz-sz/2);
	merge(rec,sz/2,&rec[sz/2],sz-sz/2,result);
	for(int i=0;i<sz;i++){
		rec[i]=result[i];
	}
}
void test(int x){
	count=0;
	stu_rec * rec=NULL;
	FILE * o;
	struct timeval t1,t2;
	double tim=0;
	if(x==start){
		o=fopen("output_ms_rec.txt","w");
		fprintf(o,"\nWorking on file with %d inputs\n",size);
		gettimeofday(&t1,NULL);
		rec=read_file(rec,"1024.txt");
		gettimeofday(&t2,NULL);
		tim=(t2.tv_sec-t1.tv_sec)*1000;
		tim+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"Time to read: %lf(ms)\n",tim);
		fclose(o);
	}else{
		rec=read_file(rec,"1024.txt");
	}	
	gettimeofday(&t1,NULL);
	merge_sort(rec,size/x);
	o=fopen("output_ms_rec.txt","a+");
	gettimeofday(&t2,NULL);
	tim=(t2.tv_sec-t1.tv_sec)*1000;
	tim+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"Time to sort %d elements: %lf(ms)\n",size/x,tim);
	fclose(o);
	free(rec);
}
void test_up(int x){
	count=0;
	stu_rec * rec=NULL;
	FILE * o;
	struct timeval t1,t2;
	double tim=0;
	if(x==2){
		o=fopen("output_ms_rec.txt","a+");
		fprintf(o,"\nWorking on file with 10240 inputs\n");
		gettimeofday(&t1,NULL);
		rec=read_file_up(rec,"10240.txt",x*size);
		gettimeofday(&t2,NULL);
		tim=(t2.tv_sec-t1.tv_sec)*1000;
		tim+=(t2.tv_usec-t1.tv_usec)/1000;
		fprintf(o,"Time to read: %lf(ms)\n",tim);
		fclose(o);
	}else{
		rec=read_file_up(rec,"10240.txt",x*size);
	}	
	gettimeofday(&t1,NULL);
	merge_sort(rec,size*x);
	o=fopen("output_ms_rec.txt","a+");
	gettimeofday(&t2,NULL);
	tim=(t2.tv_sec-t1.tv_sec)*1000;
	tim+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"Time to sort %d elements: %lf(ms)\n",size*x,tim);
	fclose(o);
	free(rec);
}
