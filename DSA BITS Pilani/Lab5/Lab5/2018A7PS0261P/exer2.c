#include <stdio.h>
#include <stdlib.h>
#include "exer2.h"
void insertInOrder(cc * arr,int i){
		int j=i-1;
		cc key=arr[j+1];
		while(j>=0&&arr[j].cno>key.cno){
			arr[j+1]=arr[j];
			j--;
		}	
		arr[j+1]=key;
}
void insertionSort(cc * arr,int index){
	if(index<=0){
		FILE * op=fopen("exe2_stack_size.txt","a+");
		unsigned long cl;
		unsigned long * ptr=&cl;
		fprintf(op,"%lu\n",base_add-ptr);
		fclose (op);
		return;
	}
	insertionSort(arr,index-1);//sort array of n-1
	insertInOrder(arr,index);//insert at right index
}
