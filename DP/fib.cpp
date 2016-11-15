#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
LL Fib[1000000];
void pre()
{
    Fib[1]=1;
    Fib[2]=1;
    for(LL i=3;i<1000000;++i)
        Fib[i]=(Fib[i-1]+Fib[i-2])%MOD;
}
int main()
{
    pre();
    LL Q,N,Arr[100000],Sum[100000],i,j,ans;
    Sum[0]=0;
    cin>>Q;
    while(Q--)
    {
        ans=0;
        scanf("%lld",&N);
        for(i=1;i<=N;++i)
        {
            scanf("%lld",&Arr[i]);
            Sum[i]=(Sum[i-1]+Arr[i])%MOD;
        }

        for(i=0;i<N;++i)
        {
            for(j=i+1;j<=N;++j)
            {
                if(Sum[j]>=Sum[i])
                    ans=(ans+Fib[Sum[j]-Sum[i]])%MOD;
                else
                {
                    ans=(ans+Fib[Sum[j]-Sum[i]+MOD])%MOD;
                }

            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

