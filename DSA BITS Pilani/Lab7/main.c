#include "exer1.h"
int first=1;
int main(int argc,char ** argv){
	rec * arr=NULL;
	if(argc<3){
		return 1;
	}
	puts("STARTING");
	arr=read_file(argv[1]);
	printf("Successfully read %s\n",argv[1]);
	int size=atoi(argv[1]);
	printf("size: %d\n",size);
	rec *	arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	int cut_sz=estimateCutoff(arr_cpy,size,1,size-1);
	printf("Cut Size: %d\n",cut_sz);
	tt tmp;
	
	tmp=sort(arr,size,cut_sz);
	write_file(argv[2],arr,size,cut_sz,tmp);
	
	free(arr);
	free(arr_cpy);
	puts("DONE");
	printf("%s generated\n",argv[2]);
}
rec * read_file(char * fname){
	FILE * in=fopen(fname,"r");
	if(!in){
		puts("Error in opening file");
		exit(1);
	}
	int size=atoi(fname);
	rec * arr=malloc(size*sizeof(rec));
	int i=0;
	while(fscanf(in,"%s %d",arr[i].name,&arr[i].empID)!=EOF){
		i++;
	}
	fclose(in);
	return arr;
}
void write_file(char * fname,rec arr[],int size,int cut_sz,tt time){
	FILE * op;
	if(first){
		op=fopen(fname,"w");
		first=0;
	}else{
		op=fopen(fname,"a+");
	}
	if(!op){
		puts("Here");
		return;
	}
	fprintf(op,"ARRAY SIZE: %d\nCUTOFF SIZE :%d\n",size,cut_sz);
	fprintf(op,"QUICK SORT(With Sublist Constarint=%d) TIME(in ms): %.6lf\n",cut_sz,time.qs);
	fprintf(op,"INSERTION SORT(Entire Array after quick sort) TIME(in ms): %.6lf\n",time.is);
	fprintf(op,"------------------------------------------------\n\n");
	fclose(op);
}
