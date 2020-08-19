#include "hashing.h"

int main(){
	// Exercise1
	char ** arr=parse();
	profile(arr);
	//Exercise2
	
	hashTable *h=NULL;
	h=create_table();
	printf("Insertion Cost for All strings: %d\n",insertAll(h,arr));
	printf("Lookup Cost for 100%% strings: %d\n",lookupAll(h,arr,1));
	stats(h);	
	
	//EXERCISE3
	float cut=0.0f;
	for(float fi=0.2f;fi<2.1f;fi+=0.1f){
		printf("Lookup Cost for %.2f %% strings: %d\n",fi*100,lookupAll(h,arr,fi));
		if(h->queryingCost<=h->insertionCost){	
			cut=fi;
		}
	}
	printf("Cut-off value: %.2f or %.2f %%\n",cut,cut*100);
	cleanup(h);
	cut=0.0f;
	for(float fi=0.2f;fi<2.1f;fi+=0.1f){
		printf("Lookup Cost for %.2f %% strings: %d\n",fi*100,lookupAll(h,arr,fi));
		if(h->queryingCost<=h->insertionCost){	
			cut=fi;
		}
	}
	printf("Cut-off value: %.2f or %.2f %%\n",cut,cut*100);
	free(h);
	free(arr);
}
//EXERCISE 3
void cleanup(hashTable *h){
	FILE * in=fopen("stopwords.txt","r");
	char tmp[50];
	while(fscanf(in,"%s",tmp)!=EOF){
		fgetc(in);
		if(lookup(h,tmp)!=NULL){
			int pos=hashFunction(tmp,base,tab_size);
			rec * curr=h->arr[pos];
			if(strcmp(curr->str,tmp)==0){
				h->arr[pos]=curr->next;
				free(curr);
				continue;
			}else{
				rec * prev=curr;
				curr=curr->next;
				while(curr!=NULL){
					if(strcmp(curr->str,tmp)==0){
						prev->next=curr->next;
						free(curr);
						continue;
					}
					prev=curr;
					curr=curr->next;
				}
			}
		}
	}
	fclose(in);
	puts("-----------------------------------------------");
	puts("FILE CLEANED UP");
	puts("-----------------------------------------------");
}