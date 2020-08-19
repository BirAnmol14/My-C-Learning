#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int main(int argc , char * argv[]){
	if(argc==2){
		Stack * s=init_stack(s);
		FILE * in=fopen(argv[1],"r");
		if(in==NULL){
			printf("ERROR!\n");exit(1);
		}
		int num;
		while(fscanf(in,"%d",&num)!=EOF){
			push(s,num);
		}
		while(s->head->count!=0){
			pop(s);
		}
	}else{
		printf("Error, please give one input file\n");exit(1);
	}
}
