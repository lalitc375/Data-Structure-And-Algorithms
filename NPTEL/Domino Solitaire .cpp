#include<bits/stdc++.h>
using namespace std;

long long int  maxTile(long long int Arr[][2],int n)
{
    long long int DP[n+3];
    long i;
    for(i=0;i<n+3;++i)
    DP[i]=0;
    DP[n]=abs(Arr[n][0]-Arr[n][1]);
    for(i=n-1;i>=1;--i)
    {
        DP[i]=max(DP[i+1]+abs(Arr[i][0]-Arr[i][1]),DP[i+2]+abs(Arr[i][0]-Arr[i+1][0])+abs(Arr[i][1]-Arr[i+1][1]));
       // cout<<DP[i]<<" "<<i<<endl;
    }

    return DP[1];
}
int main()
{
    long int n,i;
    cin>>n;
    long long int A[n+1][2];
    for(i=1;i<=n;++i)
        cin>>A[i][0];
    for(i=1;i<=n;++i)
        cin>>A[i][1];
    cout<<maxTile(A,n);
    return 0;
}
