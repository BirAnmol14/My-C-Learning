#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "exer1.h"
int main(){
	cc * arr=(cc*)malloc(size*sizeof(cc));
	struct timeval t1,t2;
	double elapsedtime;
	FILE * o=fopen("output_exe1.txt","w");
	if(o){
	fprintf(o,"Time for 10 files: ");
	gettimeofday(&t1,NULL);
	arr=read_file(arr,"10");
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;

	fprintf(o,"Time for 100 files: ");
	gettimeofday(&t1,NULL);
	arr=read_file(arr,"100");
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	
	fprintf(o,"Time for 1000 files: ");
	gettimeofday(&t1,NULL);
	arr=read_file(arr,"1000");
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	
	fprintf(o,"Time for 10000 files: ");
	gettimeofday(&t1,NULL);
	arr=read_file(arr,"10000");
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;

	fprintf(o,"Time for 100000 files: ");
	gettimeofday(&t1,NULL);
	arr=read_file(arr,"100000");
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	
	fprintf(o,"Time for 1000000 files: ");
	gettimeofday(&t1,NULL);
	for(int i=0;i<10;i++){
	arr=read_file(arr,"100000");
	}
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	}
	puts("Output stored in file output_exe1.txt");
	fclose(o);
}
