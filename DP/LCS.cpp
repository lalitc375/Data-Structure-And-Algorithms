#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;
int LCS(char A[],char B[],int m,int n)
{

    //cout<<A<<" "<<m<<endl;
    //cout<<B<<" "<<n<<endl;
    int DP[m+1][n+1];
    int i,j;
    for(i=0;i<=m;++i)
    {
        for(j=0;j<=n;++j)
        {
            if(i==0||j==0)
                DP[i][j]=0;
            else if(A[i-1]==B[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
        }
    }
    return DP[m][n];
}
int main()
{
    char A[8];
    char B[10];
    cin>>A;
    cin>>B;
    cout<<LCS(A,B,strlen(A),strlen(B))<<endl;
    return 0;
}
