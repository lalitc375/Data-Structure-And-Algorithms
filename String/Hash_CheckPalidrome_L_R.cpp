//By lalitc375
#include<bits/stdc++.h>


using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;
#define p 1000
#define MOD 1000000007
LL fast_exp(LL base,LL exp) {
    LL  res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
int main()
{
string S;
cin>>S;

LL Q,L,R,i;
LL FRomI[S.length()+1];
FRomI[0]=0;
LL FRomE[S.length()+1];
loop(i,0,S.length())
   {
    FRomI[i+1]=(LL)(FRomI[i]+S[i]*fast_exp(p,i))%MOD;
    plln(FRomI[i+1]);
   }

FRomE[S.length()]=0;
for(i=S.length()-1;i>=0;--i)
 {
    FRomE[i]=(LL)(FRomE[i+1]+S[i]*fast_exp(p,S.length()-i-1))%MOD;
    plln(FRomE[i]);
}



sll(Q);
while(Q--)
{
    sll(L); sll(R);
    if((FRomI[R+1]-FRomI[L])==(FRomE[L]-FRomE[R+1]))
       printf("Yes\n");
    else
        printf("No\n");
}
return  0;
}





