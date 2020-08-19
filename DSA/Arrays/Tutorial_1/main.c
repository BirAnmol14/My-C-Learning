#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arrays Example 1-D and 2-D\n");
    int arr[10];
    printf("Enter numbers for 1-D array: \n");
    for(int i=0;i<10;i++){
        printf("Enter Value at arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe Generated 1-D Array is:\n");
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    putchar('\n');
    printf("\nEnter numbers for 2-D array: \n");
    int arr2[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("Enter Value at arr[%d][%d]: ",i,j);
            scanf("%d",&(arr2[i][j]));
        }
    }
    printf("\nThe Generated 2-D Array is:\n");
    for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                 printf("%d\t",arr2[i][j]);
            }
            putchar('\n');
    }
    putchar('\n');
    return 0;
}
