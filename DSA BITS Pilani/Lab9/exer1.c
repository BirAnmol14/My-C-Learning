#include "hashing.h"
int size=0;
int tab_size=0;
long long int base=0;
int abs(int x){
	return (x>0?x:-1*x);	
}
int hashFunction(char string[],long long baseNum,int tableSize){
	//Problem with the given hash function
	//The ASCII sum of characters is always < baseNum and tableSize
	// Therefore the hashFunction remains same for all cases
	//What Question Wanted
	/* 
	int sum=0;
	for(int i=0;i<strlen(string);i++){
		sum+=string[i];
	}
	*/
	//My implementation
	int sum=7;
	for(int i=0;i<strlen(string);i++){
		sum*=31;
		sum+=string[i];
	}
	return abs((sum%baseNum)%tableSize);
}
int collisionCount(char ** arr,long long baseNum,int tableSize){
	
	int count=0;
	int *val=malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
		val[i]=hashFunction(arr[i],baseNum,tableSize);
	}
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(val[i]==val[j]){
				count++;
				break;
			}
		}
	}
	free(val);
	return count;
}
char ** parse(){
	FILE * in=fopen("aliceinwonderland.txt","r");
	if(!in){
		puts("error opening file");
		return NULL;
	}
	int count=0;
	size=5;
	char **arr;
	arr=(char **)malloc(size*sizeof(char *));
	if(in){
		char tmp[50];
		while(fscanf(in,"%s",tmp)!=EOF){
			fgetc(in);
			if(arr[count]==NULL){
				arr[count]=malloc(50*sizeof(char));
			}
			int flag=1;
			if(strlen(tmp)==1&&!isalpha(tmp[0])){
				flag=0;
			}else{
				for(int i=0;i<strlen(tmp);i++){
					if(isdigit(tmp[i])||tmp[i]=='('||tmp[i]==')'){
						flag=0;
					}
				}
			}
			if(flag){
				if(tmp[strlen(tmp)-1]==':'||tmp[strlen(tmp)-1]=='?'||tmp[strlen(tmp)-1]=='\''||tmp[strlen(tmp)-1]=='!'||tmp[strlen(tmp)-1]==';'||tmp[strlen(tmp)-1]==','||tmp[strlen(tmp)-1]=='.'||tmp[strlen(tmp)-1]=='\"'||tmp[strlen(tmp)-1]=='\''){
					tmp[strlen(tmp)-1]='\0';
				}
				strcpy(arr[count],tmp);
				count++;
				if(count==size){
					size*=2;
					arr=(char **)realloc(arr,size*sizeof(char*));
				}
			}
		}		
	}
	arr=(char **)realloc(arr,count*sizeof(char*));
	printf("Number of valid strings: %d\n",count);
	size=count;
	fclose(in);
	return arr;
}
void profile(char ** arr){
	int tabSize[]={5000,50000,500000};
	long long int baseNum[][6]={{5003,7537,9973,67867967,86028121,104395301},{51001 ,74189,90971,198491329,236887691,533000389},{565273,611071,611953,512927357,533000389,553105243}};
	int cost[18];
	int k=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			cost[k]=collisionCount(arr,baseNum[i][j],tabSize[i]);
			printf("Table Size: %d\tbase number: %lld\tcollision count: %d\n",tabSize[i],baseNum[i][j],cost[k]);
			k++;
		}
	}
	int min_ind=0;
	for(int i=0;i<18;i++){
		if(cost[i]<cost[min_ind]){
			min_ind=i;
		}
	}
	puts("-------------------------------------");
	tab_size=tabSize[min_ind/6];
	base=baseNum[min_ind/6][min_ind%6];
	printf("Best Pair is\nTableSize: %d,Base Number: %lld\n",tab_size,base);
}
