#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
int main(){
	srand(time(0));
	while(1){
		puts("");
		int m=rand()%15001+10000;
		printf("Val of m: %d\n",m);
		int * arr=myalloc(m,sizeof(int));
		if(arr==NULL){
			printf("Allocation Failed\n");exit(1);
		}
		printf("Memory size on heap:%d\n",heap_mem_allocated);
		printf("Address of starting loc: %u\n",arr);
		printf("Address of last location: %u\n",&arr[m-1]);
		myfree(arr,m,sizeof(int));
		printf("Memory size on heap:%d\n",heap_mem_allocated);
		puts("");
	}
}
//HEAP has a lot of free space and does not get full so eaily as compared to stack
