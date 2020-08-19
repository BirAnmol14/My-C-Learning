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
/*
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
*/
 size=10;
 list[0].id=1;
 list[0].pri=0;
 list[0].at=1;
 list[0].et=5;
 list[1].id=2;
 list[1].pri=1;
 list[1].at=9;
 list[1].et=3;
 list[2].id=3;
 list[2].pri=2;
 list[2].at=11;
 list[2].et=12;
 list[3].id=4;
 list[3].pri=0;
 list[3].at=4;
 list[3].et=7;
 list[4].id=5;
 list[4].pri=1;
 list[4].at=8;
 list[4].et=2;
 list[5].id=6;
 list[5].pri=2;
 list[5].at=12;
 list[5].et=11;
 list[6].id=7;
 list[6].pri=0;
 list[6].at=3;
 list[6].et=9;
 list[7].id=8;
 list[7].pri=1;
 list[7].at=7;
 list[7].et=4;
 list[8].id=9;
 list[8].pri=2;
 list[8].at=13;
 list[8].et=10;
 list[9].id=10;
 list[9].pri=0;
 list[9].at=2;
 list[9].et=15;
 /* ele[0].pri = ele[3].pri = ele[6].pri = PRI_0;
 ele[1].pri = ele[4].pri = ele[7].pri = PRI_1;
 ele[2].pri = ele[5].pri = ele[8].pri = ele[9].pri = PRI_2;
 for (i=0;i<MAX;i++)
 {
  ele[i].id = i+1;
  ele[i].et = i+2;
  ele[i].at = i;
 }
 ele[2].at = 10;
 ele[5].at = 1;
 ele[6].at = 5;*/
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
    /*
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
    */
    //MODIFIED
    for(int i=0;i<3;i++){
        s[i]=createlist();
        for(int j=0;j<size;j++){
            if(list[j].pri==i){
                s[i]=insert(list[j],s[i]);
            }
        }
    }
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
 //seq[0] = createlist();
 //seq[1] = createlist();
 //seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list);
}
