#include "exer1.h"
void insertion_sort(rec arr[],int n){
	for(int i=0;i<n-1;i++){
		rec key=arr[i+1];
		int j;
		for( j=i;j>=0;j--){
			if(arr[j].empID>key.empID){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
		}
		arr[j+1]=key;
	}
}
