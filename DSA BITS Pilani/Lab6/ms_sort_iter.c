#include "exer1.h"
#include <sys/time.h>
#include <math.h>
#define start 10
int * base=0; int * top=0;
void test(int);
void test_up(int);
int min(int x1,int x2){
	if(x1<x2){
		return x1;
	}
	return x2;
}
int main(){
	int t=size;base=&t;
	for(int i=start;i>=1;i--){
		test(i);
	}
	for(int i=2;i<=start;i++){
		test_up(i);
	}
	puts("Output produced in output_ms_iter.txt");
}
void  merge_sort(stu_rec * rec,int sz){
	if(rec==NULL){
		return;
	}
	int i;
	for(i=1;i<=sz;i*=2){
		for(int j=0;j<sz-1;j=j+2*i){
			int l=j;
			int r=min(j+i*2-1,sz-1);
			int mid=min(j+i-1,sz-1);
			stu_rec result[r-l+1];
			merge(&rec[l],mid-l+1,&rec[mid+1],r-mid,result);	
			for(int k=0;k<r-l+1;k++){
				rec[k+j]=result[k];
			}
			
		}				
	}	
	FILE * o=fopen("output_ms_iter.txt","a+");
	top=&sz;
	fprintf(o,"Stack space used: %d\n",abs(top-base)*4);
	fclose(o);
}
void test(int x){
	stu_rec * rec=NULL;
	FILE * o;
	struct timeval t1,t2;
	double tim=0;
	if(x==start){
		o=fopen("output_ms_iter.txt","w");
		fprintf(o,"Working on file with %d inputs\n",size);
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
	o=fopen("output_ms_iter.txt","a+");
	gettimeofday(&t2,NULL);
	tim=(t2.tv_sec-t1.tv_sec)*1000;
	tim+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"Time to sort %d elements: %lf(ms)\n",size/x,tim);
	fclose(o);
	free(rec);
}
void test_up(int x){
	stu_rec * rec=NULL;
	FILE * o;
	struct timeval t1,t2;
	double tim=0;
	if(x==2){
		o=fopen("output_ms_iter.txt","a+");
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
	o=fopen("output_ms_iter.txt","a+");
	gettimeofday(&t2,NULL);
	tim=(t2.tv_sec-t1.tv_sec)*1000;
	tim+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"Time to sort %d elements: %lf(ms)\n",size*x,tim);
	fclose(o);
	free(rec);
}

