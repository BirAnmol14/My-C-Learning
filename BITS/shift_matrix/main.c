#include <stdio.h>
#include <stdlib.h>
#define COLS 4
#define ROWS 3
void pm(int mat[][COLS]);
void pm1(int mat[]);
void shiftmat(int *,int );
void printmat(int mat[][COLS]);
int main()
{
    int mat[ROWS][COLS],shift[ROWS];
    puts("Fill the matrix: ");
    pm(mat);
    puts("Tell shift values: ");
    pm1(shift);
    for(int i=0;i<ROWS;i++)
    {
        shiftmat(mat[i],shift[i]);
    }
    printmat(mat);
    return 0;
}
void pm(int mat[][COLS])
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
           scanf(" %d",&mat[i][j]);
        }
    }
    return ;
}
void pm1(int mat[])
{
    for(int j=0;j<ROWS;j++)
        {
            scanf(" %d",&mat[j]);
        }
        return ;
}
void shiftmat(int * p,int x)
{
    int tmp[COLS];
    for(int j=0;j<COLS;j++)
    {
        if(j+x<COLS){tmp[j+x]=p[j];}
        else {tmp[(j+x)%COLS]=p[j];}
    }
      for(int j=0;j<COLS;j++)
    {
        p[j]=tmp[j];
    }
    return ;
}
void printmat(int mat[][COLS])
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        putchar('\n');
    }
    return ;
}
/*DATA:
3   4   -2  16
12  76  0   5
16  7   100 -70
1   4   6
*/
