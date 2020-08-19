#include "exer1.h"
Stack * init(Stack * st, int n){
	st=malloc(1*sizeof(Stack));
	st->s_arr=malloc(n*sizeof(int));
	st->len=n;
	st->top=-1;
}
void push(Stack * st,int val){
	if(st==NULL){
		return;
	}	
	if(st->top==st->len-1){
		st->len*=2;
		st->s_arr=realloc(st->s_arr,st->len*sizeof(int));
	}
	st->top++;
	st->s_arr[st->top]=val;
}
int pop(Stack * st){
	if(st->top==-1){
		puts("UnderFlow");
		return -99999;
	}
	int tmp=st->s_arr[st->top];
	st->top--;
	return tmp;
}
int peek(Stack * st){
	if(st->top==-1){
		puts("Error");
		return -99999;
	}
	return st->s_arr[st->top];
}
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

void quick_sort(rec arr[],int n,int s){
	Stack * st=NULL;
	st=init(st,n);
	push(st,0);
	push(st,n-1);
	while(st->top>=0){
		int right=pop(st);
		int left=pop(st);
		int piv;
		if(right-left+1>s){
			piv=partition(arr,left,right);
		}else{
			continue;
		}
		if(s>=1){
			if(piv-left>s){
				push(st,left);
				push(st,piv-1);
			}
			if(right-piv>s){
				push(st,piv+1);
				push(st,right);
			}
		}else{
			if(piv-1>left){
				push(st,left);
				push(st,piv-1);
			}
			if(piv+1<right){
				push(st,piv+1);
				push(st,right);
			}		
		}
	}
	free(st);
}
int partition(rec arr[],int left,int right){
	//Pivot selection based on last element 
	int piv=right;
	int i=left-1;
	int j=left;
	while(j<=piv){
		if(arr[j].empID<=arr[piv].empID){
			i++;
			rec tmp=arr[j];
			arr[j]=arr[i];
			arr[i]=tmp;
		}		
		j++;
	}
	return i;
}

void reset(rec org_arr[],rec new_arr[],int size){
	for(int i=0;i<size;i++){
		new_arr[i]=org_arr[i];
	}
}
double absd(double val){
	return val<0?-1*val:val;
}
tt testRun(rec arr[],int size){
	tt temp;
	rec* arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	struct timeval t1,t2;

	gettimeofday(&t1,NULL);
	insertion_sort(arr,size);
	gettimeofday(&t2,NULL);
	temp.is=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.is+=(t2.tv_usec-t1.tv_usec)/1000.00;
	

	gettimeofday(&t1,NULL);
	quick_sort(arr_cpy,size,0);
	gettimeofday(&t2,NULL);
	temp.qs=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.qs+=(t2.tv_usec-t1.tv_usec)/1000.00;
	free(arr_cpy);
	return temp;
}
int estimateCutoff(rec arr[],int size,int min,int max){
	if(min<=0||min>=size||max<=1||max>=size){
		puts("Error");return -99999;
	}
	rec* arr_cpy=malloc(size*sizeof(rec));
	reset(arr,arr_cpy,size);
	tt t1,t2;
	t1=testRun(arr_cpy,min);
	
	reset(arr,arr_cpy,size);
	t2=testRun(arr_cpy,max);
	
	reset(arr,arr_cpy,size);
	tt tmp;double diff;int mid;
	do{
		mid=(min+max)/2;
		tmp=testRun(arr_cpy,mid);
		if(tmp.is>tmp.qs){
			max=mid;
		}else if(tmp.qs>tmp.is){
			min=mid;
		}
		diff=tmp.is-tmp.qs;
		reset(arr,arr_cpy,size);
	}while(absd(diff)>est);
	free(arr_cpy);
	return mid;
}
void print_list(rec arr[] , int n){
	for(int i=0;i<n;i++){
		printf("%s\t%d\n",arr[i].name,arr[i].empID);
	}
}
tt sort (rec arr[],int size,int cut_sz){
	rec * arr_cpy=malloc(size*sizeof(rec));
	for(int i=0;i<size;i++){
		arr_cpy[i]=arr[i];
	}
	tt temp;
	struct timeval t1,t2;

	gettimeofday(&t1,NULL);
	quick_sort(arr,size,cut_sz);
	gettimeofday(&t2,NULL);
	temp.qs=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.qs+=(t2.tv_usec-t1.tv_usec)/1000.00;
	free(arr_cpy);

	gettimeofday(&t1,NULL);
	insertion_sort(arr,size);
	gettimeofday(&t2,NULL);
	temp.is=(t2.tv_sec-t1.tv_sec)*1000.00;
	temp.is+=(t2.tv_usec-t1.tv_usec)/1000.00;

	
	return temp;
	
}

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
