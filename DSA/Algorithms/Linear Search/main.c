#include <stdio.h>
#include <stdlib.h>
//O(n)
int lin_search(int arr[],int n,int* key){
    for(int i=0;i<n;i++){
        if(arr[i]== *key){
            return i;
        }
    }
    return -1;
}
int main()
{
    printf("Linear Search\n");
    int arr[10];
    srand(time(NULL));
    printf("Randomly Generated Array:\n");
    for(int i=0;i<10;i++){
        arr[i]=rand();
        printf("%d\t",arr[i]);
    }
    putchar('\n');
    int key;
    printf("Enter Number to Search: ");
    scanf("%d",&key);
    int ans=lin_search(arr,10,&key);
    if(ans==-1){
        printf("Not Found\n");
    }else{
    printf("Found at Index: %d",ans);
    }
    return 0;
}
