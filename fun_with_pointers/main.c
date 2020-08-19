#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("hi\n");
    int* arr=malloc(10*sizeof(int));
    for (int i=0;i<9;i++)
    {scanf("%d",(arr+i));
    printf("address: %d;value: %d\n",(arr+i),*(arr+i));
    printf("address: %d;value: %d\n\n",&arr[i],arr[i]);
    }
    free(arr);
    return 0;
}
