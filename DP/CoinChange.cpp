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
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL two(LL n) {return (1LL<<n);}
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}

bool compare(LL i, LL j) {return i<j;};

#define max_Coins 250
#define max_Sum 250
LL coins[max_Coins+5];
LL DP[max_Coins+5][max_Sum+5];
LL changePossible(LL m,LL sum_required)
{
    if(sum_required==0)
        return 1;
    else if(m<0 || sum_required<0)
        return 0;
    return changePossible(m-1,sum_required)+changePossible(m,sum_required-coins[m]);
}
LL changePossibleDP(LL m,LL sum_required)
{
    LL i,j;
    loop(i,0,m+1)
    {
    DP[i][0]=1;
    }
    loop(i,0,m+1)
    {
        loop(j,1,sum_required+1)
        {
            DP[i][j]=0;
            if((i-1)>=0)
                DP[i][j]+=DP[i-1][j];
            if((j-coins[i])>=0)
                DP[i][j]+=DP[i][j-coins[i]];
        }
    }
    return DP[m][sum_required];
}

int main()
{
    coins[0]=1;
    coins[1]=2;
    coins[2]=5;
    LL N,M,i;
    sll2(N,M);
    loop(i,0,M) sll(coins[i]);
    printf("%lld\n",changePossibleDP(M-1,N));
    return 0;
}





