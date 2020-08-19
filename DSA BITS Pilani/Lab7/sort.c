#include "exer1.h"
tt sort (rec arr[],int size,int cut_sz){
	rec * arr_cpy=malloc(size*sizeof(rec));
	for(int i=0;i<size;i++){
		arr_cpy[i]=arr[i];
	}
	tt temp;
	struct timeval t1,t2;

	gettimeofday(&t1,NULL);
	quick_sort(arr,size,cut_sz);
	gettimeofday(&t2,NULL);
	temp.qs=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.qs+=(t2.tv_usec-t1.tv_usec)/1000.00;
	free(arr_cpy);

	gettimeofday(&t1,NULL);
	insertion_sort(arr,size);
	gettimeofday(&t2,NULL);
	temp.is=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.is+=(t2.tv_usec-t1.tv_usec)/1000.00;

	
	return temp;
	
}
