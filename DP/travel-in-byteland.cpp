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

int main()
{
    LL T,i,k,j,ans,N,M,D;
    sl2(N,M);
    LL temp;
    vector<vector<int> >Arr(N+5,vector<int>(M+5));
    vector<LL>sumRow(M+5);
    vector<vector<LL> >sumCol(N+5,vector<LL>(M+5));
    vector<vector<LL> >sumDig(N+5,vector<LL>(M+5));
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            scanf("%d",&Arr[i][j]);
    sumRow[1]=Arr[1][1];
    sumCol[1][1]=Arr[1][1];
    sumDig[1][1]=Arr[1][1];
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=M;++j)
        {
            if(i==1)
            {
                if(j==1)
                    continue;
                else
                {
                    temp=((sumRow[j-1])*Arr[i][j])%MOD;
                    sumRow[j]=(temp+sumRow[j-1])%MOD;
                    sumDig[i][j]=temp;
                    sumCol[i][j]=temp;
                }
            }
            else
            {
             if(j==1)
                {
                    temp=((sumCol[i-1][j])*Arr[i][j])%MOD;
                    sumRow[j]=temp;
                    sumDig[i][j]=temp;
                    sumCol[i][j]=temp+sumCol[i-1][j];
                }
                else
                {
                    temp=((sumRow[j-1]+sumCol[i-1][j]+sumDig[i-1][j-1])*Arr[i][j])%MOD;
                    sumRow[j]=temp+sumRow[j-1];
                    sumDig[i][j]=temp+sumDig[i-1][j-1];
                    sumCol[i][j]=temp+sumCol[i-1][j];
                }
            }
        }
    }
    pln(temp);
    return 0;
}




