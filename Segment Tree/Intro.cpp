//By lalitc375
// segment Tree for sum
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
    st[si]=ConstructSegmentTreeUtil(Arr,ss,mid,st,2*si+1)+ConstructSegmentTreeUtil(Arr,mid+1,se,st,2*si+2);
    return st[si];
}
LL getSumUtil(LL *st,LL ss,LL se,LL qs,LL qe,LL si)
{
    if(ss>=qs && se<=qe)
        return st[si];
    if(ss>qe||se <qs)
        return 0;
    LL mid=(ss+se)/2;
    return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,2*si+2);
}
LL getSum(LL * st,LL n,LL qs,LL qe)
{
    return getSumUtil(st,0,n-1,qs,qe,0);
}
void updateSegmentTreeUtil(LL *st,LL ss,LL se,LL index,LL si,LL diff)
{
    plln(ss);
    plln(se);
    //plln(index);
    putchar('\n');
    if(ss>index || se<index)
        return;
    st[si]+=diff;
    if(se==ss)
        return;
    LL mid=(se+ss)/2;
    updateSegmentTreeUtil(st,ss,mid,index,2*si+1,diff);
    updateSegmentTreeUtil(st,mid+1,se,index,2*si+2,diff);
}


void updateSegmentTree(LL *st,LL *Arr, LL n,LL index,LL new_val)
{
    LL diff=new_val-Arr[index];
    Arr[index]=new_val;
    updateSegmentTreeUtil(st,0,n-1,index,0,diff);
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
    LL Arr[]={1,2,3,4,5};
    LL len=sizeof(Arr)/sizeof(Arr[0]);
    LL *st=ConstructSegmentTree(Arr,len);
    cout<<getSum(st,len,2,2)<<endl;
    //updateSegmentTree(st,Arr,len,3,5);
    cout<<getSum(st,len,2,3);
    return 0;
}
