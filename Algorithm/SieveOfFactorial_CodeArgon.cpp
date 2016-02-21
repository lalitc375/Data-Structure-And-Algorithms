#include<bits/stdc++.h>
using namespace std;
long long cnt[1000005]={0};
void sieve()
{
    long i,N,k;
    for(i=2;i<1000005;++i)
    {
        if(!cnt[i])
        {
            for(N=i;N<1000005;N+=i)
            {
                k=N;
                while(k%i==0)
                {
                        cnt[N]++;           //Counting Powers of Prime in N
                        k=k/i;
                }
            }
        }
    }
    for(i=2;i<1000005;++i)  //Cummative Sum Of Powers OF Prime
        cnt[i]+=cnt[i-1];
}
int main()
{
    sieve();
    long long i,N,k,sum;
    scanf("%lld",&N);
    long long Arr[N];
    for(i=0;i<N;++i)
        scanf("%lld",&Arr[i]);
    long long j=(1<<N);
    long long  Sum=0;
    for(i=1;i<j;i++)
    {
       sum=0;
        for(k=0;k<N;++k)                // Bit Manipulation TO Generate All subset OF set wirh N element
        {
            if(i&(1<<k))
                sum+=cnt[Arr[k]];
        }
        if(!(sum&1))
            Sum+=sum;
    }
    printf("%lld",Sum);
    return 0;
}

