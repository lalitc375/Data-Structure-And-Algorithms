#include<bits/stdc++.h>
using namespace std;
int knapSack(int W,int profit[],int wieght[],int n)
{
    int DP[n+1][W+1],i,j,w;
    for(i=0;i<=n;++i)
    {
        for(w=0;w<=W;++w)
        {
            if(i==0||w==0)
                DP[i][w]=0;
            else if(w>=wieght[i-1])
                DP[i][w]=max(DP[i-1][w],profit[i-1]+DP[i-1][w-wieght[i-1]]);
            else
                DP[i][w]=DP[i-1][w];
            cout<<DP[i][w]<<" ";
        }
        cout<<endl;
    }
    return DP[n][W];
}

int main()
{
    int profit[]={1,10,1,5,60};
    int weigth[]={1,1,2,2,3};
    cout<<knapSack(6,profit,weigth,5);
    return 0;
}
