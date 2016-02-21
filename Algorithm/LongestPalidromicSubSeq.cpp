#include<bits/stdc++.h>

using namespace std;
int LPSS(char A[],int start,int end1)
{
    if(start==end1)
        return 1;
    else if(start>end1)
        return 0;
    else if(A[start]==A[end1])
        return 2+LPSS(A,start+1,end1-1);
    else
        return max(LPSS(A,start+1,end1),LPSS(A,start,end1-1));
}
int LPSSDP(char A[])
{
    int size1=strlen(A);
    int DP[size1][size1];
    memset(DP,0,sizeof(DP));
    int i,j,k;
    for(i=0;i<size1;++i)    DP[i][i]=1;
    for(i=2;i<=size1;++i)
    {
        for(j=0;j<size1-i+1;++j)
        {
            k=j+i-1;
            if(A[j]==A[k] && i==2)
                DP[j][k]=2;
            else if(A[j]==A[k])
                DP[j][k]=2+DP[j+1][k-1];
            else
    for(i=0;i<size1;++i)
                DP[j][k]=max(DP[j+1][k],DP[j][k-1]);
        }
    }

        {
        for(j=0;j<size1;++j)
            cout<<DP[i][j]<<"\t";
            cout<<"\n";
        }


    return DP[0][size1-1];
}
int LPSSDP_A(char A[],char B[])
{
    int size1=strlen(A);
    int i,j,k;
    int DP[size1+5][size1+5];
    memset(DP,0,sizeof(DP));
    for(i=size1;i>=1;--i)
    {
        for(j=1;j<=size1-i+1;++j)
        {
            k=j+i-1;
            DP[j][k]=max(DP[j][k],DP[j-1][k]);
            DP[j][k]=max(DP[j][k],DP[j][k+1]);
            if(A[j-1]==A[k-1])
                DP[j][k]=max(DP[j][k],DP[j-1][k+1]+1+(j!=k));

        }
    }
    int max1=0,max2=0;
    int size2=sizeof(B);
    int DP1[size2+5][size2+5];
    memset(DP1,0,sizeof(DP1));
    for(i=size2;i>=1;--i)
    {
        for(j=1;j<=size2-i+1;++j)
        {
            k=j+i-1;
            DP1[j][k]=max(DP1[j][k],DP1[j-1][k]);
            DP1[j][k]=max(DP1[j][k],DP1[j][k+1]);
            if(B[j-1]==B[k-1])
                DP1[j][k]=max(DP1[j][k],DP1[j-1][k+1]+1+(j!=k));

        }
    }
    for(i=1;i<=size1;++i)    max1=max(max1,DP[i][i]);
    for(j=1;j<=size2;++j)    max2=max(max2,DP1[i][i]);
    cout<<max1<<endl<<max2<<endl;
    if(max1%2==0||max2%2==0)
        return max1+max2;
    else
    {
        int Arr[26]={0},Brr[26]={0};
        for(i=1;i<=size1;++i)   if(DP[i][i]==max1) Arr[A[i]-'a']=1;
        for(i=1;i<=size2;++i)   if(DP1[i][i]==max2) Brr[B[i]-'a']=1;
        for(i=0;i<26;++i)
            if(Arr[i]&Brr[i])
                return max1+max2;
        return max1+max2-1;
    }
}
int main()
{
    char A[1005];
    char B[1005];
    long T;
    scanf("%ld",&T);
    while(T--)
    {
       scanf("%s",A);
        scanf("%s",B);
    //cout<<LPSS(A,0,strlen(A)-1)<<endl;
    cout<<LPSSDP_A(A,B)<<endl;
    }
    return 0;
}
