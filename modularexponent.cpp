#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL modExponent(LL a,LL b,LL c)
{
    LL ans=1;
    while(b!=0)
    {
        if(b&1)            ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return ans;
}
int main()
{
    cout<<modExponent(3,5,3);
}
