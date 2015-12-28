//By lalitc375
#include<bits/stdc++.h>
#define LL long
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
#define mx 50000

LL Arr[mx];
LL Sum[mx];
struct node
{
    LL ls; LL rs; LL ms;
};
struct node ST[4*mx+1];

void  build(LL low,LL high,LL si)
{

    if(low==high)
    {
        ST[si]=(struct  node){Arr[low],Arr[low],Arr[low]};
        return ;
    }
    LL mid=(low+high)/2;
    build(low,mid,2*si+1);
    build(mid+1,high,2*si+2);
    struct node Left=ST[2*si+1],Right=ST[2*si+2];
    ST[si].ms=max(Left.ms,max(Right.ms,Left.rs+Right.ls));
    ST[si].ls=max(Left.ls,Sum[mid+1]-Sum[low]+Right.rs);
    ST[si].rs=max(Right.rs,Sum[high+1]-Sum[mid+1]+Left.rs);
}
struct node query(LL x,LL y,LL low,LL high,LL si)
{
//    debug(low);
  //  debug(high);
    if(low==x && high==y)
        return ST[si];
    LL mid;
    mid=(low+high)/2;
    if (x>mid)
        return query(x,y,mid+1,high,2*si+2);
    else if(mid>=y)
        return query(x,y,low,mid,2*si+1);

    struct node Left=query(x,mid,low,mid,2*si+1);
    struct node Right=query(mid+1,y,mid+1,high,2*si+2);
    return ((struct node) {max(Left.ls,Sum[mid+1]-Sum[low]+Right.rs),
            max(Right.rs,Sum[high+1]-Sum[mid+1]+Left.rs),
            max(Left.ms,max(Right.ms,Left.rs+Right.ls))});
}

LL L,R,N,i,Q;

int main()
{
    sl(N);
    sl(Arr[0]);
    Sum[0]=0;

    Sum[1]=Arr[0];
    loop(i,1,N)
    {
        sl(Arr[i]);
        Sum[i+1]=Sum[i]+Arr[i];
    }
    build(0,N-1,0);
    sl(Q);
    while(Q--)
    {
        sl2(L,R);
        printf("%ld\n",query(L-1,R-1,0,N-1,0).ms);
    }
    return 0;
}




