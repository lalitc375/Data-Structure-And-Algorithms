//By lalitc375
#include<bits/stdc++.h>
#define LL int

using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)

#define sll(n) scanf("%lld",&n)
#define sl(n) scanf("%ld",&n)
#define s(n) scanf("%d",&n)
#define MOD 1000000007
LL DP[1L<<26];
LL Arr[1000006];
int main()
{
    LL T;
    s(T);
    while(T--)
    {
        string A;
        cin>>A;
        LL len=A.length();
        long i,j,k,Q=0,P,pre=0;
        DP[0]=1;
        Arr[0]=0;
        k=1;
        for(i=0;i<len;++i)
        {
            pre^=(1L<<(A[i]-'a'));
            Q+=DP[pre];
            for(j=0;j<26;++j)
                Q+=DP[pre^(1L<<j)];
            DP[pre]++;
            Arr[k++]=pre;
        }
        for(i=0;i<k;++i)
            DP[Arr[i]]=0;
        P=len;
        P*=(len+1);
        P/=2;
        i=__gcd(P,Q);
        printf("%ld/%ld\n",Q/i,P/i);
    }
    return 0;
}

