#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "emp_rec.h"
#include "stack.h"
typedef struct tt{
	double is;
	double qs;
}tt;
void quick_sort(rec [],int,int);
int partition(rec [],int,int);
void insertion_sort(rec [],int);
tt sort(rec [],int,int);
void print_list(rec [],int);
tt testRun(rec [],int );
int estimateCutoff(rec [],int,int ,int );
rec * read_file(char *);
void write_file(char *,rec [],int,int,tt);
void reset(rec org_arr[],rec new_arr[],int size);
