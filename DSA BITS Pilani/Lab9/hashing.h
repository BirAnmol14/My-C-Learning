#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern int size;
extern int tab_size;
extern long long int base;
typedef struct rec{
 char str[50];
 int count;
 struct rec * next; 
}rec;

typedef struct ht{
 int elementCount;
 int insertionCost;
 int queryingCost;
 rec ** arr;
} hashTable;
//EXERCISE3
void cleanup(hashTable *h);
//Exercise2
rec * newRec(char * s);
hashTable * create_table(); 
void insert(hashTable * h,char ** arr,int index);
int insertAll(hashTable * h,char ** arr);
rec * lookup(hashTable * h,char * str);
int lookupAll(hashTable * h,char ** arr,float m);
void stats(hashTable *h);
//Exercise1
int hashFunction(char string[],long long baseNum,int tableSize);
int collisionCount(char ** arr,long long baseNum,int tableSize);
char ** parse();
void profile(char ** arr);

