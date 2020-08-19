#include <stdio.h>
#include <stdlib.h>
typedef struct record{
	char name[11];
	float cg;
}stu_rec;
extern int size;
extern int rec_read;
void merge(stu_rec ls1[],int sz1,stu_rec ls2[],int sz2,stu_rec ls[]);
stu_rec * read_file(stu_rec *,char *);
stu_rec * read_file_up(stu_rec *,char *,int);
void print_rec(stu_rec * ,int);
void merge_sort(stu_rec *,int sz);
