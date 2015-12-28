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
#define Mx  20000
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}

bool A[Mx];
void pre()
{
    LL i,j;
    for( i=0;i<Mx;++i)   A[i]=true;
    A[0]=false;
    A[1]=false;
    for(i=2;i<Mx;i++)
    {
        if(A[i])
        {
            //plln(i);
            for(j=i+i;j<Mx;j=j+i)
                A[j]=false;
        }
    }
}
int main()
{
    pre();
    LL T;
    sll(T);
    if(A[T])
        cout<<T;
    else
        cout<<"No";

    return 0;
}




