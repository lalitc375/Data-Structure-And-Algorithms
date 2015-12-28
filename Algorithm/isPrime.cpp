//By lalitc375
#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define sll(n) scanf("%lld",&n)
#define sl(n) scanf("%ld",&n)
#define br putchar('\n')
#define MOD 1000000007
#define debug(x) cout << '>' << #x << ':' << x << endl;
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}

bool isPrime(LL N)
{
    LL sqr=(LL)sqrt(N);
    for(LL i=2;i<=sqr;++i)
        if((N%i)==0)    return 0;
    return 1;
}


int main()
{
    LL T;
    sll(T);
    if(isPrime(T))
        cout<<T;
    else
        cout<<"No";
    return 0;
}





