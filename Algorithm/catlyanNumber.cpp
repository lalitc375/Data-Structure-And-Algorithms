#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
LL binomialCoefficient(LL n ,LL r)
{
    if(r>n-r)
        r=n-r;
    LL res=1;
    for(LL i=0;i<r;++i)
    {
        res*=(n-i);
        res/=(i+1);
        res%=MOD;
    }
    return res;
}
LL catlanNumber(LL n)
{
    if(n==0)
        return 1;
    return binomialCoefficient(2*n,n)/(n+1);
}
LL catlanNum[2005];

void calculateCatlanNumber()
{
    catlanNum[0]=1;
    catlanNum[1]=1;
    LL i,j;
    for(j=2;j<=2000;++j)
    {
        for(i=0;i<j;++i)
            catlanNum[j]=(catlanNum[j]+catlanNum[i]*catlanNum[j-i-1])%MOD;
    }
}
int main()
{

    cout<<catlanNumber(0)<<" "<<catlanNumber(1)<<" "<<catlanNumber(2)<<" "<<catlanNumber(10);
    return 0;
}
