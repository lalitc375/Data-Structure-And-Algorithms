#include<bits/stdc++.h>
using namespace std;
int DP[1000][1000];
int getAns(string &str1,string &str2,int i,int j)
{
    if(DP[i][j]!=-1)
        return DP[i][j];
    if(!str1[i])
        {
            int k;
            int ans=0;
            for(k=j;k<str2.length();++k)
                ans=ans+(str2[k]-'0');
            DP[i][j]=ans;
            return ans;
        }
    else if(!str2[j])
        {
            int k;
            int ans=0;
            for(k=i;k<str1.length();++k)
                ans=ans+(str1[k]-'0');
            DP[i][j]=ans;
            return ans;
        }
    else if(str1[i]==str2[j])
        {
            DP[i][j]=getAns(str1,str2,i+1,j+1);
            return DP[i][j];
        }
      DP[i][j]=min(str1[i]-'0'+getAns(str1,str2,i+1,j),str2[j]-'0'+getAns(str1,str2,i,j+1));
    return DP[i][j];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j;
        string str1="816337897";
        string str2="816393804";
        cin>>str1;
        cin>>str2;

        for(i=0;i<=str1.length();++i)
            for(j=0;j<=str2.length();++j)
                DP[i][j]=-1;

        cout<<getAns(str1,str2,0,0)<<endl;
    }

    return 0;
}
