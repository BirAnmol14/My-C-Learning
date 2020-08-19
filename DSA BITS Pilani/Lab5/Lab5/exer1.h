#define size 10
typedef struct cc{
	long long int cno;
	char bankcode[6];
	char exp_date[8];
	char fname[50];
	char lname[50];	
}cc;
extern int max_capacity;
extern int curr_index;
cc* read_file(cc *,char *);
void printarr(cc *);
