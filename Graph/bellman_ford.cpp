#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[4][4]={{0,5,-1,500},{500,0,2,-2},{500,500,0,3},{4,500,500,0}}; // weight Matrix
    //int W[4][4][4]={0};
    int i,j,k;
    int D[4];
    D[0]=INT_MAX/2;         // Initial
    D[1]=INT_MAX/2;
    D[2]=INT_MAX/2;
    D[3]=INT_MAX/2;
    int source=2;       //Source Vertex
    D[source]=0;
    for(k=0;k<3;++k)
    {
        for(i=0;i<4;++i)
            for(j=0;j<4;++j)
            D[j]=min(D[j],D[i]+A[i][j]);
    }
    for(i=0;i<4;++i)
        cout<<D[i]<<endl;
    return 0;
}

