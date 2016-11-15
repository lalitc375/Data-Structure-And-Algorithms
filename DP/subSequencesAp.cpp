#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000009
using namespace std;
LL Arr[200000+5],DP[105][105];
LL power(LL x, LL y)
{
    LL res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%MOD;

        // n must be even now
        y = y>>1; // y = y/2
        x = (x*x)%MOD;  // Change x to x^2
    }
    return res;
}
int main()
{
        LL N,i,j,sum=0;
        LL count1[105]={0};
        scanf("%lld",&N);

        for(i=1;i<=N;++i)
            scanf("%lld",&Arr[i]);

        for(i=1;i<=N;++i)
        {
            count1[Arr[i]]++;
            for(j=1;j<Arr[i];++j)
            {
                sum+=(DP[Arr[i]-j][j]+count1[Arr[i]-j])%MOD ;
                DP[Arr[i]][j]+=DP[Arr[i]-j][j];
                DP[Arr[i]][j]+=count1[Arr[i]-j];
                DP[Arr[i]][j]%=MOD;

            }
        }
      //  cout<<sum<<endl;
        memset(DP,0,sizeof(DP));
        memset(count1,0,sizeof(count1));
        for(i=N;i>=1;--i)
        {
            for(j=1;j<Arr[i];++j)
            {
                sum+=(DP[Arr[i]-j][j]+count1[Arr[i]-j])%MOD;
                DP[Arr[i]][j]+=DP[Arr[i]-j][j];
                DP[Arr[i]][j]+=count1[Arr[i]-j];
                DP[Arr[i]][j]%=MOD;
            }
            count1[Arr[i]]++;
        }
        //cout<<sum<<endl;
        for(i=1;i<=100;++i)
            sum=(sum+(power(2,count1[i])-1))%MOD;
        cout<<(sum+1)%MOD<<endl;
    return 0;
}
