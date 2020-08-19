#include "hashing.h"
rec * newRec(char *s){
	rec * tmp=malloc(1*sizeof(rec));
	strcpy(tmp->str,s);
	tmp->count=1;
	tmp->next=NULL;
	return tmp;
}
hashTable * create_table(){
	hashTable * h=malloc(1*sizeof(hashTable));
	h->elementCount=0;
	h->insertionCost=0;
	h->queryingCost=0;
	h->arr=malloc(tab_size*sizeof(rec*));
	for(int i=0;i<tab_size;i++){
		h->arr[i]=NULL;
	}
	return h;
}
void insert(hashTable * h,char ** arr,int index){
	int pos=hashFunction(arr[index],base,tab_size);
	if(h->arr[pos]==NULL){
		h->arr[pos]=newRec(arr[index]);
		return;
	}else{
		rec * tmp=h->arr[pos];
		if(strcmp(tmp->str,arr[index])==0){
			tmp->count++;
			h->insertionCost++;
			return;
		}
		while(tmp->next!=NULL){
			h->insertionCost++;
			if(strcmp(tmp->str,arr[index])==0){
				tmp->count++;
				return;
			}
			tmp=tmp->next;
		}
		tmp->next=newRec(arr[index]);
		return;
	}
}
int insertAll(hashTable * h,char ** arr){
	free(h);
	h=create_table(h);
	for(int i=0;i<size;i++){
		insert(h,arr,i);
	}
	return h->insertionCost;
}
rec * lookup(hashTable * h,char * str){
	int pos=hashFunction(str,base,tab_size);
	if(h->arr[pos]==NULL){
		return NULL;
	}
	else{
		rec * tmp=h->arr[pos];
		h->queryingCost++;
		if(strcmp(tmp->str,str)==0){
			return tmp;
		}
		while(tmp!=NULL){
			h->queryingCost++;
			if(strcmp(tmp->str,str)==0){
				return tmp;
			}
			tmp=tmp->next;
		}
		return tmp;
	}
}
int lookupAll(hashTable * h,char ** arr,float m){
	h->queryingCost=0;
	m*=size;
	int max=(int)m;
	if(max<=size){
		for(int i=0;i<max;i++){
			lookup(h,arr[i]);
		}
	}
	else{
		for(int i=0;i<max/size;i++){
			for(int j=0;j<size;j++){
				lookup(h,arr[j]);
			}
		}
		max=max%size;
		for(int j=0;j<max;j++){
			lookup(h,arr[j]);
		}
	}
	return h->queryingCost;
}
void stats(hashTable * h){
	FILE * out=fopen("stats.txt","w");
	fprintf(out,"STATS\n");
	int used=0;
	for(int i=0;i<tab_size;i++){
		if(h->arr[i]){
			int loc=0;
			used++;
			rec * tmp=h->arr[i];
			while(tmp!=NULL){
				loc++;
				fprintf(out,"%s occurs %d times\n",tmp->str,tmp->count);
				tmp=tmp->next;
			}
			fprintf(out,"%d strings mapped at index %d \n",loc,i);
			fprintf(out,"----------------------------------------------------\n");
		}
	}
	fprintf(out,"----------------------------------------------------\n");
	printf("----------------------------------------------------\n");
	puts("stats.txt generated");
	printf("----------------------------------------------------\n");
	fprintf(out,"%d indices used\t; %d free indices\n",used,tab_size-used);
	fprintf(out,"----------------------------------------------------\n");
	fclose(out);
}