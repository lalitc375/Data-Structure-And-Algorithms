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
#define debug(x) cout << '>' << #x << ':' << x << endl;
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(LL n) {  return __builtin_popcountll(n); }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}



struct Line
{
    LL A;
    LL B;
    LL C;
};
bool compare(const struct Line &p,const struct Line &q)
{
    if(p.A==q.A)
    {
        if(p.B==q.B)
            return p.C<q.C;
        else
            return p.B<q.B;
    }
    else
        return p.A<q.A;
}

int main()
{
    struct Line Arr[5];
    cout<<__gcd(-4,0)<<endl;
    Arr[0]=(struct Line){1,2,3};
    Arr[1]=(struct Line){3,2,3};
    Arr[2]=(struct Line){1,3,3};
    Arr[3]=(struct Line){1,3,4};
    Arr[4]=(struct Line){1,2,3};
    sort(Arr,Arr+5,compare);
    LL i;
    for(i=0;i<5;++i)
        cout<<Arr[i].A<<" "<<Arr[i].B<<" "<<Arr[i].C<<endl;
    return 0;
}



