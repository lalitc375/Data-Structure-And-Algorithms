//By lalitc375
#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define pn(n) prLLf("%d\n",n)
#define pln(n)  prLLf("%ld\n",n)
#define plln(n) prLLf("%lld\n",n)
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
inline LL ones(LL n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(LL & n, LL b) { n |= two(b); }
inline void unset_bit(LL & n, LL b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}

#define Mx 1000000

LL ST[Mx];
LL Lz[Mx];

LL build(LL Arr[],LL si,LL low, LL high)
{
    if(low==high)
    {
            ST[si]=Arr[low];
            //cout<<low<<" "<<high<<" "<<ST[si]<<endl;
            return ST[si];
    }
    LL mid=(low+high)/2;
    ST[si]=build(Arr,2*si+1,low,mid)+build(Arr,2*si+2,mid+1,high);
//    cout<<low<<" "<<high<<" "<<ST[si]<<endl;
    return ST[si];
}

void upd(LL id,LL l,LL r,LL x){//	increase all members in this LLerval by x
	Lz[id] += x;
	ST[id] += (r - l+1) * x;
}


void shift(LL id,LL l,LL r){//pass update information to the children
	LL mid = (l+r)/2;
	upd(id * 2+1, l, mid, Lz[id]);
	upd(id * 2+2, mid+1, r, Lz[id]);
	Lz[id] = 0;// passing is done
}

void increase(LL x,LL y,LL val,LL id,LL l,LL r){
	if(x > r or l > y)	return ;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return ;
	}
	shift(id, l, r);
	LL mid = (l+r)/2;
	increase(x, y, val, id * 2+1, l, mid);      //increase leaf node
	increase(x, y, val, id*2+2, mid+1, r);
	ST[id] = ST[id * 2+1] + ST[id * 2 + 2];
}
LL sum(LL x,LL y,LL id,LL l,LL r){
	if(x <= l && r <= y)	return ST[id];
	if(x >r || l > y)	return 0;
	shift(id, l, r);
	LL mid = (l+r)/2;
    LL Sum=sum(x, y, id * 2+1, l, mid) +sum(x, y, id * 2 + 2, mid+1, r);
	return Sum;
}
int main()
{
    LL i;
    LL Arr[]={59,10,20,40,5,6};
    loop(i,0,24) ST[i]=0;
    loop(i,0,24) Lz[i]=0;
    loop(i,0,6) cout<< Arr[i] << " ";
    cout<<endl;
    build(Arr,0,0,5);

    cout<<sum(0,2,0,0,5)<<endl;
    increase(0,2,5,0,0,5);
    cout<<sum(0,2,0,0,5);
    increase(0,2,-5,0,0,5);
    increase(2,2,+5,0,0,5);
   cout<<endl<<sum(0,2,0,0,5);
    return 0;


}




