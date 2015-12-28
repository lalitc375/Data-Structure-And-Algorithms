//By lalitc375
// Set is implemented using BST
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
#define debug(x) cout << '>' << #x << ':' << x << endl;
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
bool compare(LL i, LL j) {return i<j;};

int main()
{
    set <LL> St;
    LL T,i,k,j,ans,N,D;
    St.insert(9);
    St.insert(6);
    St.insert(8);
    St.insert(4);
    St.insert(1);

    set <LL>::iterator Itr,itr;
    Itr=St.begin();
    cout<<*Itr<<endl;
    Itr=St.find(9);
    if(Itr==St.end())
        cout<<"Element Not Found"<<endl;
    else
        cout<<"Element Found"<<endl;
    for(itr=St.begin();itr!=St.end();++itr)
        cout<<*itr<<endl;
    St.erase(5);
    cout<<endl;
    for(itr=St.begin();itr!=St.end();++itr)
        cout<<*itr<<endl;
    return 0;
}




