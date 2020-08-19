#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "exer2.h"
unsigned long* base_add;
int main(){
	
	FILE * o=fopen("output_exe2.txt","w");
	unsigned long cl;
	base_add=&cl;	
	FILE * op;
	cc * arr=(cc*)malloc(10*sizeof(cc));
	struct timeval t1,t2;
	double elapsedtime;
	
	fprintf(o,"Time for sorting file with 10 records: ");
	op=fopen("exe2_stack_size.txt","w+");
	fprintf(op,"Size of heap for 10 records: ");
	fclose(op);
	arr=read_file(arr,"10");
	gettimeofday(&t1,NULL);
	insertionSort(arr,curr_index);
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	
	fprintf(o,"Time for sorting file with 100 records: ");
	op=fopen("exe2_stack_size.txt","a+");
	fprintf(op,"Size of heap for 100 records: ");
	fclose(op);
	arr=read_file(arr,"100");
	gettimeofday(&t1,NULL);
	insertionSort(arr,curr_index);
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;

	fprintf(o,"Time for sorting file with 1,000 records: ");
	op=fopen("exe2_stack_size.txt","a+");
	fprintf(op,"Size of heap for 1,000 records: ");
	fclose(op);
	arr=read_file(arr,"1000");
	gettimeofday(&t1,NULL);
	insertionSort(arr,curr_index);
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;

	fprintf(o,"Time for sorting file with 10,000 records: ");
	op=fopen("exe2_stack_size.txt","a+");
	fprintf(op,"Size of heap for 10,000 records: ");
	fclose(op);
	arr=read_file(arr,"10000");
	gettimeofday(&t1,NULL);
	insertionSort(arr,curr_index);
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;
	
	fprintf(o,"Time for sorting file with 1,00,000 records: ");
	op=fopen("exe2_stack_size.txt","a+");
	fprintf(op,"Size of heap for 1,00,000 records: ");
	fclose(op);
	arr=read_file(arr,"100000");
	gettimeofday(&t1,NULL);
	insertionSort(arr,curr_index);
	gettimeofday(&t2,NULL);
	elapsedtime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedtime+=(t2.tv_usec-t1.tv_usec)/1000;
	fprintf(o,"%lf(ms)\n",elapsedtime);
	curr_index=-1;max_capacity=size;

	
	fclose(o);
	puts("Output File for time i.e. output_exe2.txt generated");
	puts("Output File for stack space i.e. exe2_stack_size.txt generated");
	FILE * op1,*op2,*op3;
	op1=fopen("output_exe2.txt","r");
	op2=fopen("exe2_stack_size.txt","r");
	op3=fopen("final_output_exe2.txt","w");
	if(op1&&op2&&op3){
		char ch;
		while((ch=fgetc(op1))!=EOF){
			fprintf(op3,"%c",ch);
			if(ch=='\n'){
				char ch1;
				while((ch1=fgetc(op2))!='\n'){
					fprintf(op3,"%c",ch1);
				}
				fprintf(op3,"\n");
				fprintf(op3,"\n");

			}
		}
	}
	fclose(op1);
	fclose(op2);
	fclose(op3);
	puts("FINAL Output File i.e. final_output_exe2.txt generated");
}
