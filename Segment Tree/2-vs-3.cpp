//By lalitc375
// segment Tree for sum
#include<bits/stdc++.h>
#define LL int
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define sll(n) scanf("%lld",&n)
#define sl(n) scanf("%ld",&n)
#define MOD 1000000007
LL ConstructSegmentTreeUtil(char Arr[],LL ss,LL se,int *st,LL si)
{
    if(ss==se)
        {
            st[si]=(Arr[se]-'0');
            return st[si];
        }
    LL mid=(ss+se)/2;
    st[si]=(ConstructSegmentTreeUtil(Arr,ss,mid,st,2*si+1)*2+ConstructSegmentTreeUtil(Arr,mid+1,se,st,2*si+2))%3;
    return st[si];
}
LL getSumUtil(LL *st,LL ss,LL se,LL qs,LL qe,LL si)
{
    if(ss>=qs && se<=qe)
        return st[si];
    if(ss>qe||se <qs)
        return 0;
    LL mid=(ss+se)/2;
    return (getSumUtil(st,ss,mid,qs,qe,2*si+1)*2+getSumUtil(st,mid+1,se,qs,qe,2*si+2))%3;
}
LL getSum(LL * st,LL n,LL qs,LL qe)
{
    return getSumUtil(st,0,n-1,qs,qe,0);
}
void updateSegmentTreeUtil(int *st,LL ss,LL se,LL index,LL si,LL diff)
{
    pn(ss);
    pn(se);
    //plln(index);
    putchar('\n');
    if(ss<=index && index<=se)
        st[si]=(st[si]+diff)%3;
    if(index<=ss || index>=se)
        return ;
    LL mid=(se+ss)/2;
    updateSegmentTreeUtil(st,ss,mid,index,2*si+1,diff);
    updateSegmentTreeUtil(st,mid+1,se,index,2*si+2,diff);
}

void updateSegmentTree(LL *st,char *Arr, LL n,LL index)
{
    if(Arr[index]=='1')
        return;
    else
        Arr[index]='0';
    updateSegmentTreeUtil(st,0,n-1,index,0,1);
}
int * ConstructSegmentTree(char Arr[],LL n)
{
    LL high_bit=(LL)(log(n)/log(2));
    int * st = new int[(1<<(high_bit+1))-1];
        ConstructSegmentTreeUtil(Arr,0,n-1,st,0);
    return st;
}
int main()
{
    long N;
    scanf("%ld",&N);
    char A[N+5];
    scanf("%s",A);
    int *st=ConstructSegmentTree(A,N);
    long Q;
    sl(Q);
    while(Q--)
    {
        long l;
        sl(l);
        if(l==0)
        {
            int L,R;
            cin>>L>>R;
            cout<<getSum(st,N,L,R);
            cout<<endl;
        }
        else
        {
            long L;
            sl(L);
            updateSegmentTree(st,A,N,L);
        }

    }
    return 0;
}
