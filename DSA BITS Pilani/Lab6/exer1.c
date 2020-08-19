#include "exer1.h"
int size=1024;
int rec_read=0;
void merge(stu_rec ls1[],int sz1,stu_rec ls2[],int sz2,stu_rec ls[]){
	int i=0;
	int j=0;
	int k=0;
	while(i!=sz1 && j!=sz2){
		if(ls1[i].cg>ls2[j].cg){
			ls[k]=ls2[j];
			j++;
			k++;
		}else {
			ls[k]=ls1[i];
			i++;
			k++;
		}
	}
	while(i!=sz1){
		ls[k]=ls1[i];
		i++;
		k++;
	}
	while(j!=sz2){
		ls[k]=ls2[j];
		j++;
		k++;
	}
}
stu_rec * read_file(stu_rec * rec,char * fname){
	if(rec==NULL){
		rec=malloc(size*sizeof(stu_rec));
	}
	FILE * 	in=fopen(fname,"r");
	if(in){
		int i=0;
		stu_rec tmp;
		while(fscanf(in,"%[^,],%f\n",tmp.name,&tmp.cg)!=EOF){
			rec[i++]=tmp;
		}
		rec_read=i;
		return rec;
		fclose(in);
	}
	puts("error opening file");
	return NULL;
}
void print_rec(stu_rec * rec,int max){
	if(rec==NULL){
		return;
	}
	puts("Printing all records");
	for(int i=0;i<max;i++){
		printf("%d: %s  %.2f\n",i+1,rec[i].name,rec[i].cg);
	}
}
stu_rec * read_file_up(stu_rec * rec,char * fname,int ct){
	if(rec==NULL){
		rec=malloc(ct*sizeof(stu_rec));
	}
	FILE * 	in=fopen(fname,"r");
	if(in){
		int i=0;
		stu_rec tmp;
		while(i<ct){
			fscanf(in,"%[^,],%f\n",tmp.name,&tmp.cg);
			rec[i++]=tmp;
		}
		rec_read=i;
		return rec;
		fclose(in);
	}
	puts("error opening file");
	return NULL;
}