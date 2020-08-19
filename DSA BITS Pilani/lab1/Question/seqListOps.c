/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID ");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2) ");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time ");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time ");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{
    int curr=sl.head;
    if(sl.size==0){
        st[curr].ele=j;
        st[curr].next=-1;
        sl.size++;
        return sl;
    }
    for(int i=0;i<sl.size;i++){
        if(compare(st[curr].ele,j)==GREATER){
            Job temp=j;
            j=st[curr].ele;
            st[curr].ele=temp;
        }
        if(st[curr].next!=-1){
        curr=st[curr].next;
        }
    }
    int tmp=nextfreeloc++;
    st[tmp].next=st[curr].next;
    st[tmp].ele=j;
    st[curr].next=tmp;
    sl.size++;
    return sl;
//Implement this function
//
 }

void insertelements (JobList list , int size, SeqList s[3])
{
    for(int i=0;i<size;i++){
        int prior=list[i].pri;

       if(prior==PRI_0){
        s[0]=insert(list[i],s[0]);
       }
       else if(prior==PRI_1){
        s[1]=insert(list[i],s[1]);
       }
       else if(prior==PRI_2){
        s[2]=insert(list[i],s[2]);
       }
    }
// Implement this function

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
    int index=0;
    for(int i=2;i>-1;i--){
        int curr=s[i].head;
        for(int j=0;j<s[i].size;j++){
            ele[index]=st[curr].ele;
            curr=st[curr].next;
            index++;
        }
    }
// Implement this function

}

void printlist(SeqList sl)
{
    printf("\n");
    int curr=sl.head;
    for(int i=0;i<sl.size;i++){
        printJob(st[curr].ele);
        curr=st[curr].next;
    }
// Implement this function
}

void printJobList(JobList list, int size)
{
    printf("\n");
    for(int i=0;i<size;i++){
        printJob(list[i]);
    }
// Implement this function

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list);
}
