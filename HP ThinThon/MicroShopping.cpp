#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    LL N,Q;
    LL i,min1,max1,count1,j;
    scanf("%lld %lld",&N,&Q);
    LL Arr[N+5],a,b,c;
    for(i=1;i<=N;++i)    scanf("%lld",&Arr[i]);
    for(i=0;i<Q;++i)
    {
        count1=0;
        scanf("%lld %lld %lld",&a,&b,&c);
        for(j=a;j<=b;++j)
            if(Arr[j]<=c)    ++count1;
        printf("%lld\n",count1);
    }
    return 0;
}
