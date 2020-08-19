#include <stdio.h>
#include <stdlib.h>
#include "exer1.h"

int max_capacity=size;
int curr_index=-1;
cc* read_file(cc * arr,char * fname){
	FILE * input=fopen(fname,"r");
	if(input){
	cc tmp;
	while(fscanf(input,"\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n",&tmp.cno,tmp.bankcode,tmp.exp_date,tmp.fname,tmp.lname)!=EOF){
		if(curr_index<max_capacity-1){
			curr_index++;
			arr[curr_index]=tmp;
		}else{
			max_capacity*=2;
			arr=(cc*)realloc(arr,max_capacity*sizeof(cc));
			curr_index++;
			arr[curr_index]=tmp;
		}
	}
	}
	fclose(input);
	return arr;
}
void printarr(cc * arr){
	for(int i=0;i<=curr_index;i++){
		printf("%d\t%llu,%s,%s,%s,%s\n",i+1,arr[i].cno,arr[i].bankcode,arr[i].exp_date,arr[i].fname,arr[i].lname);
	}
}
