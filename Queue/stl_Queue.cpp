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
queue <LL>Q;
int main()
{
    if(Q.empty())
        printf("True\n");
    LL i;
    loop(i,0,5)
        Q.push(i);
    debug(Q.front());
    debug(Q.back());
    debug(Q.size());
    Q.pop();

    printf("After Popping an Element\n");
    debug(Q.front());
    debug(Q.back());
    debug(Q.size());
    return 0;
}





