#include "exer1.h"
#define est 0.0005
void reset(rec org_arr[],rec new_arr[],int size){
	for(int i=0;i<size;i++){
		new_arr[i]=org_arr[i];
	}
}
double absd(double val){
	return val<0?-1*val:val;
}
tt testRun(rec arr[],int size){
	tt temp;
	rec* arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	struct timeval t1,t2;

	gettimeofday(&t1,NULL);
	insertion_sort(arr,size);
	gettimeofday(&t2,NULL);
	temp.is=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.is+=(t2.tv_usec-t1.tv_usec)/1000.00;
	

	gettimeofday(&t1,NULL);
	quick_sort(arr_cpy,size,0);
	gettimeofday(&t2,NULL);
	temp.qs=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.qs+=(t2.tv_usec-t1.tv_usec)/1000.00;
	free(arr_cpy);
	return temp;
}
int estimateCutoff(rec arr[],int size,int min,int max){
	if(min<=0||min>=size||max<=1||max>=size){
		puts("Error");return -99999;
	}
	rec* arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	tt t1,t2;
	t1=testRun(arr_cpy,min);
	
	reset(arr,arr_cpy,size);
	t2=testRun(arr_cpy,max);
	
	reset(arr,arr_cpy,size);
	tt tmp;double diff;int mid;
	do{
		mid=(min+max)/2;
		tmp=testRun(arr_cpy,mid);
		if(tmp.is>tmp.qs){
			max=mid;
		}else if(tmp.qs>tmp.is){
			min=mid;
		}
		diff=tmp.is-tmp.qs;
		reset(arr,arr_cpy,size);
	}while(absd(diff)>est);
	free(arr_cpy);
	return mid;
}
void print_list(rec arr[] , int n){
	for(int i=0;i<n;i++){
		printf("%s\t%d\n",arr[i].name,arr[i].empID);
	}
}
