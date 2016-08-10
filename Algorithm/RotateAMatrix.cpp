#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(int matrix[4][4],int n)
{
    int layer,i,temp;
    for(layer=0;layer<n/2;++layer)
    {
        for(i=layer;i<n-layer;++i)
        {
            temp=matrix[layer][i];
            matrix[layer][i]=matrix[i][layer];
            matrix[i][layer]=matrix[n-i-1][layer];
            matrix[n-i-1][layer]=matrix[layer][n-layer-1];
            matrix[layer][n-layer-1]=temp;
        }
    }

}

int main()
{
    int matrix[4][4],i,j;
    for(i=0;i<4;++i)
        {
        for(j=0;j<4;++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    rotateMatrix(matrix,4);
    for(i=0;i<4;++i)
        {
        for(j=0;j<4;++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;

}
