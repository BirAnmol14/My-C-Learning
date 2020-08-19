#include "exer1.h"
void local_sort(char * fname,rec arr[],int size,int cut_sz);
void local_write_file(char * fname,rec arr[],int size,double time,int sort);
int main(int argc,char ** argv){
	rec * arr=NULL;
	if(argc<2){
		return 1;
	}
	puts("STARTING");
	for(int i=1;i<argc;i++){
		arr=read_file(argv[i]);
		int sz=atoi(argv[i]);
		printf("Successfully read %s\n",argv[i]);
		char * fname=malloc(100*sizeof(char));
		char * fname1=malloc(100*sizeof(char));
		strcpy(fname,argv[i]);
		strcat(fname,"_sorted");
		strcpy(fname1,fname);
		strcat(fname1,"_quick");
		local_sort(fname,arr,sz,0);
		printf("OUTPUT: %s and %s generated\n",fname,fname1);
		free(arr);
		free(fname);
		free(fname1);
	}
	
	puts("DONE");
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
void local_write_file(char * fname,rec arr[],int size,double time,int sort){
	FILE * op;
	op=fopen(fname,"w");
	if(!op){
		puts("Error");
		return;
	}
	fprintf(op,"ARRAY SIZE: %d\n",size);
	if(sort==0){
	fprintf(op,"INSERTION SORT TIME(in ms): %.6lf\n",time);
	fprintf(op,"ENTIRELY SORTED ARRAY \n");
	}
	else if(sort==1){
	fprintf(op,"QUICK SORT TIME(in ms): %.6lf\n",time);
	fprintf(op,"ENTIRELY SORTED ARRAY \n");
	}
	
	for(int i=0;i<size;i++){
		fprintf(op,"%d:\t%s %d\n",i+1,arr[i].name,arr[i].empID);
	}
	fprintf(op,"------------------------------------------------\n\n");
	fclose(op);
}
void local_sort (char * fname,rec arr[],int size,int cut_sz){
	rec *arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	tt temp;
	struct timeval t1,t2;
	char * fname1=malloc(100*sizeof(char));
	strcpy(fname1,fname);
	strcat(fname,"_insertion");
	strcat(fname1,"_quick");
	gettimeofday(&t1,NULL);
	insertion_sort(arr,size);
	gettimeofday(&t2,NULL);
	temp.is=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.is+=(t2.tv_usec-t1.tv_usec)/1000.00;
	local_write_file(fname,arr,size,temp.is,0);
	gettimeofday(&t1,NULL);
	quick_sort(arr_cpy,size,cut_sz);
	gettimeofday(&t2,NULL);
	temp.qs=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.qs+=(t2.tv_usec-t1.tv_usec)/1000.00;
	local_write_file(fname1,arr_cpy,size,temp.qs,1);
	free(arr_cpy);
	free(fname1);
	
}
