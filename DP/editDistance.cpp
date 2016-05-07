#include<bits/stdc++.h>
using namespace std;


int editDistance(char A[],char B[],int m ,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(A[m-1]==B[n-1])
        return editDistance(A,B,m-1,n-1);
    return 1+min(editDistance(A,B,m-1,n-1),min(editDistance(A,B,m,n-1),editDistance(A,B,m-1,n)));

}
int editDistanceDP(char A[], char B[], int m, int n)
{
    int DP[m+1][n+1];
    int i,j,k;
    for(i=0;i<=m;++i)
        DP[i][0]=i;
    for(j=0;j<=n;++j)
        DP[0][j]=j;
    for(i=1;i<=m;++i)
        {
        for(j=1;j<=n;++j)
            {
            if(A[i-1]==B[j-1])
                DP[i][j]=DP[i-1][j-1];
            else
                DP[i][j]=1+min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]));
            }
        }
    return DP[m][n];
}

int main()
{
    char A[]="Chauhan";
    char B[]="Chauhan";
    cout<<editDistance(A,B,strlen(A),strlen(B))<<endl;
    cout<<editDistanceDP(A,B,strlen(A),strlen(B));
    return 0;
}
