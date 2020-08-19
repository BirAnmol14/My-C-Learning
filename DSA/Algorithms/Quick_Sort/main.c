#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
void q_sort(int arr[],int l,int h);
int partition(int arr[],int l,int h);
void print(int arr[]){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    puts("");
}
int main()
{
    printf("Quick Sort!\n");
    int arr[size];
    srand(time(0));
    for(int i=0;i<size;i++){
        arr[i]=rand()%500+1;
    }
    puts("Before Sorting");
    print(arr);
    puts("After Sorting");
    q_sort(arr,0,size-1);
    print(arr);
    return 0;
}
int partition(int arr[],int l,int h){
    int piv=h;
    int i=l-1;
    int j=l;
    while(j<=h){
        if(arr[j]<=arr[piv]){
          i++;
          int tmp=arr[j];
          arr[j]=arr[i];
          arr[i]=tmp;
        }
        j++;
    }
    return i;
}

void q_sort(int arr[],int l,int h){
    if(l<h){
        int pivot=partition(arr,l,h);
        q_sort(arr,l,pivot-1);
        q_sort(arr,pivot,h);
    }
}
