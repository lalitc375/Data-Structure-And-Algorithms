    //By lalitc375
#include<bits/stdc++.h>

#define MOD 1000000007
#define LL long long
using namespace std;
void merge1(string &s)
{
    LL l=s.size();
    if(l&1)
        return ;
    string A=s.substr(0,l/2),B=s.substr(l/2,l);
    merge1(A);
    merge1(B);
    s=min(A+B,B+A);
}

int main()
{
    string s1,s2;
    cin>>s1;cin>>s2;
    merge1(s1);merge1(s2);
    if(s1==s2) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    return 0;
}
