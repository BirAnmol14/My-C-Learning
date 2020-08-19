#include <stdio.h>
#include <stdlib.h>
int bin_search(int [] , int , int , int);
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int key=7;
    int found=bin_search(arr,key,0,9);
    if(found==-1){
        printf("Not found\n");
    }else{
        printf("Found at index: %d",found);
    }
    return 0;
}
int bin_search(int arr[], int key, int low , int high){
    if(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(key<arr[mid]){
        high=mid-1;
        return bin_search(arr,key,low,high);
    }
    else{
        low=mid+1;
        return bin_search(arr,key,low,high);
    }
    }
    return -1;
}
