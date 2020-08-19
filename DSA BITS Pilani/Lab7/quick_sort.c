#include "exer1.h"
void quick_sort(rec arr[],int n,int s){
	Stack * st=NULL;
	st=init(st,n);
	push(st,0);
	push(st,n-1);
	while(st->top>=0){
		int right=pop(st);
		int left=pop(st);
		int piv;
		if(right-left+1>s){
			piv=partition(arr,left,right);
		}else{
			continue;
		}
		if(s>=1){
			if(piv-left>s){
				push(st,left);
				push(st,piv-1);
			}
			if(right-piv>s){
				push(st,piv+1);
				push(st,right);
			}
		}else{
			if(piv-1>left){
				push(st,left);
				push(st,piv-1);
			}
			if(piv+1<right){
				push(st,piv+1);
				push(st,right);
			}		
		}
	}
	free(st);
}
int partition(rec arr[],int left,int right){
	//Pivot selection based on last element 
	int piv=right;
	int i=left-1;
	int j=left;
	while(j<=piv){
		if(arr[j].empID<=arr[piv].empID){
			i++;
			rec tmp=arr[j];
			arr[j]=arr[i];
			arr[i]=tmp;
		}		
		j++;
	}
	return i;
}
