//By lalitc375
#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define plln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sl(n) scanf("%ld",&n)
#define sl2(a,b) scanf("%ld %ld",&a,&b)
#define sl3(a,b,c) scanf("%ld %ld %ld",&a,&b,&c)
#define br putchar('\n')
#define MOD 1000000007
#define Mx 50

#define debug(x) cout << '>' << #x << ':' << x << endl;
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
bool compare(LL i, LL j) {return i<j;};
LL DP[Mx];
int main()
{
    LL T,N,i,j,k,max_End,max_sum,max_sum1;
    sll(T);
    while(T--)
    {

        sll(N);
        LL Arr[N+5];
        loop(i,0,N) sll(Arr[i]);
        max_End=Arr[0];
        max_sum=Arr[0];
        if(Arr[0]>0)    max_sum1=Arr[0];
        else    max_sum1=0;
        loop(i,1,N)
        {
            max_End+=Arr[i];
            max_sum=max(max_End,max_sum);
            if(Arr[i]>0)
                max_sum1+=Arr[i];
            if(max_End<0)   max_End=0;
        }
        if(max_sum1==0)            printf("%lld %lld\n",max_sum,max_sum);
        else            printf("%lld %lld\n",max_sum,max_sum1);
    }
    return 0;
}




