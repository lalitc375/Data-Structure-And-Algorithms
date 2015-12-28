//By lalitc375
// segment Tree for sum
#include<bits/stdc++.h>
#define LL long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define sll(n) scanf("%ld",&n)
#define sl(n) scanf("%ld",&n)
#define MOD 1000000007
LL ConstructSegmentTreeUtil(LL Arr[],LL ss,LL se,int *st,LL si)
{
    if(ss==se)
        {
            st[si]=(Arr[se]%2);
            return st[si];
        }
    LL mid=(ss+se)/2;
    st[si]=ConstructSegmentTreeUtil(Arr,ss,mid,st,2*si+1)+ConstructSegmentTreeUtil(Arr,mid+1,se,st,2*si+2);
    return st[si];
}
LL getSumUtil(int *st,LL ss,LL se,LL qs,LL qe,LL si)
{
    if(ss>=qs && se<=qe)
        return st[si];
    if(ss>qe||se <qs)
        return 0;
    LL mid=(ss+se)/2;
    return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,2*si+2);
}
LL getNoODD(int * st,LL n,LL qs,LL qe)
{
    return getSumUtil(st,0,n-1,qs,qe,0);
}
LL getNoEven(int * st,LL n,LL qs,LL qe)
{
        return (qe-qs+1)-getSumUtil(st,0,n-1,qs,qe,0);
}
void updateSegmentTreeUtil(int *st,LL ss,LL se,LL index,LL si,LL diff)
{
    //plln(ss);
    //plln(se);
    //plln(index);
    //putchar('\n');
    if(ss>index || se<index)
        return;

    st[si]+=diff;

    if(se==ss)
        return;
    LL mid=(se+ss)/2;
    updateSegmentTreeUtil(st,ss,mid,index,2*si+1,diff);
    updateSegmentTreeUtil(st,mid+1,se,index,2*si+2,diff);
}



void updateSegmentTree(int *st,LL *Arr, LL n,LL index,LL new_val)
{
    LL diff;
    if(((new_val)%2)==(Arr[index]%2))
            return;
    else if(((new_val)%2)==0&&(Arr[index]%2)==1)
        diff=-1;
    else
        diff=1;

    Arr[index]=new_val;
    updateSegmentTreeUtil(st,0,n-1,index,0,diff);
}
int * ConstructSegmentTree(LL Arr[],LL n)
{
    LL high_bit=(LL)(log(n)/log(2));
    int * st = new int[(1<<(high_bit))-1];
    ConstructSegmentTreeUtil(Arr,0,n-1,st,0);
    return st;
}
int main()
{
    LL N,i,j;
    sll(N);
    LL Arr[N+5];
    loop(i,0,N) sll(Arr[i]);
    int *st=ConstructSegmentTree(Arr,N);
    //loop(i,1,N+1)  plln(Arr[i]);
    LL Q;
    sll(Q);
    while(Q--)
    {
        LL x;
        sll(x);
        if(x==0)
        {
            scanf("%ld %ld",&i,&j);
            updateSegmentTree(st,Arr,N,i-1,j);
        }
        else if(x==1)
        {
            scanf("%ld %ld",&i,&j);
            printf("%ld\n",getNoEven(st,N,i-1,j-1));
        }
        else if(x==2)
        {
            scanf("%ld %ld",&i,&j);
            printf("%ld\n",getNoODD(st,N,i-1,j-1));
        }
    }
    return 0;
}


