//By lalitc375
// segment Tree for LCM
#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define sll(n) scanf("%lld",&n)
#define sl(n) scanf("%ld",&n)
#define MOD 1000000007
LL ConstructSegmentTreeUtil(LL Arr[],LL ss,LL se,LL *st,LL si)
{
    if(ss==se)
        {
            st[si]=Arr[se];
            return st[si];
        }
    LL mid=(ss+se)/2;
    LL left=ConstructSegmentTreeUtil(Arr,ss,mid,st,2*si+1);
    LL right=ConstructSegmentTreeUtil(Arr,mid+1,se,st,2*si+2);
    st[si]=(right*left)/__gcd(right,left);
    return st[si];
}

LL getLcmUtil(LL *st,LL ss,LL se,LL qs,LL qe,LL si)
{
    //plln(ss);
    //plln(se);
    //putchar('\n');
    if(ss>=qs && se<=qe)
        return st[si];
    if(ss>qe||se <qs)
        return 1;
    LL mid=(ss+se)/2;
    LL left=getLcmUtil(st,ss,mid,qs,qe,2*si+1);
    LL right=getLcmUtil(st,mid+1,se,qs,qe,2*si+2);
    return  (right*left)/__gcd(right,left);
}
LL getLcm(LL * st,LL n,LL qs,LL qe)
{
    return getLcmUtil(st,0,n-1,qs,qe,0);
}

LL updateSegmentTreeUtil(LL *st,LL ss,LL se,LL index,LL si,LL new_val)
{
    if(ss>index || se<index)
        return st[si];
    if(ss==se&&ss==index)
    {
        st[si]=new_val;
        return st[si];
    }
    LL mid=(ss+se)/2;
    LL left=updateSegmentTreeUtil(st,ss,mid,index,2*si+1,new_val);
    LL right=updateSegmentTreeUtil(st,mid+1,se,index,2*si+2,new_val);
    st[si]=(right*left)/__gcd(right,left);
    return st[si];
}

void updateSegmentTree(LL *st,LL *Arr, LL n,LL index,LL new_val)
{
    LL diff=new_val-Arr[index];
    Arr[index]=new_val;
    updateSegmentTreeUtil(st,0,n-1,index,0,new_val);
}
LL * ConstructSegmentTree(LL Arr[],LL n)
{
    LL high_bit=(LL)(log(n)/log(2));
    LL * st = new LL[(1<<(high_bit+1))-1];
    ConstructSegmentTreeUtil(Arr,0,n-1,st,0);
    return st;
}
int main()
{
    LL Arr[100005],i;
    for(i=1;i<100005;++i)
        A[i-1]=i;
    LL len=sizeof(Arr)/sizeof(Arr[0]);
    LL *st=ConstructSegmentTree(Arr,len);
    cout<<getLcm(st,len,1,3)<<endl;
    updateSegmentTree(st,Arr,len,0,3);

    cout<<getLcm(st,len,1,2)<<endl;
    updateSegmentTree(st,Arr,len,2,4);
    updateSegmentTree(st,Arr,len,4,4);

    loop(i,0,len)
        plln(Arr[i]);
    return 0;
}
