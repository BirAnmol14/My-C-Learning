#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4
void getpassengertraffic(int [MAX][MAX]);
void printmatrix(int [MAX][MAX]);
void findmaxt(int [MAX][MAX]);
void reciprocalt(int [MAX][MAX]);
int maxt=0,mint;
int main()
{
    int mat[MAX][MAX];
    getpassengertraffic(mat);
    findmaxt(mat);
    reciprocalt(mat);
    printmatrix(mat);
    return 0;
}
void getpassengertraffic(int mat[MAX][MAX])
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++){scanf(" %d",&mat[i][j]);}
    }return ;
}
void findmaxt(int mat[MAX][MAX])
{int mat1[MAX][MAX];
       for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            mat1[i][j]=mat[i][j];
            if(maxt<(mat[i][j]+mat[j][i]))
            {
                maxt=mat[i][j]+mat[j][i];
            }
        }
    }
    puts("Maximum traffic is:");printf("%d\n",maxt);
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(maxt==(mat1[i][j]+mat1[j][i]))
            {
                printf("MAX traffic between cities i=%d and j=%d\n",i+1,j+1);
                mat1[i][j]=-1;mat1[j][i]=-1;
            }
        }
    }return ;
}
void reciprocalt(int mat[MAX][MAX])
{int mat1[MAX][MAX];mint=0;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(i!=j)
            {mat1[i][j]=mat[i][j];
            if(mint<abs(mat[i][j]-mat[j][i]))
            {
                mint=abs(mat[i][j]-mat[j][i]);
            }
            }
        }
    }puts("Minimum traffic is:");printf("%d\n",mint);
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(i!=j)
            {
            if(mint==abs(mat1[i][j]-mat1[j][i]))
            {
                printf("Reciprocal traffic between cities i=%d and j=%d\n",i+1,j+1);
                mat1[i][j]=-1;mat1[j][i]=-1;
            }
            }
        }
    }return ;
}
void printmatrix(int mat[MAX][MAX])
{
    puts("city\t1\t2\t3\t4");
    for(int i=0;i<MAX;i++)
    { printf("%d\t",i+1);
        for(int j=0;j<MAX;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        putchar('\n');
    }
}
/*
0   54  220 43
64  0   85  110
432 67  0   100
53  188 105 0
*/

