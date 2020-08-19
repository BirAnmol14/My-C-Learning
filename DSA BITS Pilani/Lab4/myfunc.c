#include <stdlib.h>
#include <stdio.h>
#include "ex2.h"
int heap_mem_allocated=0;
void * myalloc(int amount , int size){
	heap_mem_allocated+=amount*size;
	return malloc(amount*size);
}
void myfree(void * ptr,int amount,int size){
	heap_mem_allocated-=amount*size;
	free(ptr);
}
