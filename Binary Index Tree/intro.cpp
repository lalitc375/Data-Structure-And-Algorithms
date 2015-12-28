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
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
bool compare(LL i, LL j) {return i<j;};

// Bit Introduction


void updateBIT(LL BIT[],LL index,LL val,LL len)   // Here Index is index of val in array ARR
{
    index=index+1;
    while(index<=len)
    {
        BIT[index]+=val;
        index+=index&(-index);
    }
}

LL getCummSum(LL BIT[],LL index)
{
    LL sum=0;
    index=index+1;
    while(index>0)
    {
        sum+=BIT[index];
        index-=(index)&(-index);
    }
    return sum;
}
void update(LL BIT[],LL Arr[],LL index,LL new_val,LL len)
{
    LL diff=new_val-Arr[index];
    Arr[index]=new_val;
    updateBIT(BIT,index,diff,len);
}
LL * constructBIT(LL Arr[],LL len)
{
    LL * BIT=new LL[len+1];
    LL i;
    loop(i,0,len+1) BIT[i]=0;
    loop(i,1,len+1) updateBIT(BIT,i-1,Arr[i-1],len);
    return &BIT[0];
}

int main()
{
    LL Arr[]={10,2,4,5,1,6};
    LL *BIT=constructBIT(Arr,sizeof(Arr)/sizeof(Arr[0]));

    update(BIT,Arr,0,4,sizeof(Arr)/sizeof(Arr[0]));
    cout<<getCummSum(BIT,4);
    return 0;
}





