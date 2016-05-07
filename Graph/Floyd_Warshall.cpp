#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[4][4]={{0,5,-1,500},{500,0,2,-2},{500,500,0,3},{4,500,500,0}};
    int W[4][4][4]={0};
    int i,j,k;
    for(i=0;i<4;++i)
        for(j=0;j<4;++j)
            W[0][i][j]=min(A[i][j],A[i][0]+A[0][j]);        //Through Node 0
    for(k=1;k<4;++k)            //Through Node 1,2,3
    {
        for(i=0;i<4;++i)
            for(j=0;j<4;++j)
            W[k][i][j]=min(W[k-1][i][j],W[k-1][i][k]+W[k-1][k][j]);
    }
    for(i=0;i<4;++i)
    {

        for(j=0;j<4;++j)
        {
            printf("%d ",W[3][i][j]);
        }
    printf("\n");
    }
    return 0;
}
