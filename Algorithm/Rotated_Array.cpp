//By lalitc375
#include<bits/stdc++.h>
#define LL long
#define loop(i,a,b) for(i=a;i<b;++i)
#define plln(n) printf("%lld\n",n)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define sll(n) scanf("%lld",&n)
#define sl(n) scanf("%ld",&n)
#define s(n) scanf("%d",&n)
#define MOD 1000000007
using namespace std;
LL RotatedArray(LL Arr[],LL low,LL high,LL N) // Return Number of Times Sorted Array is Rotated
{   //There Should Be No Duplicates in  Sorted Array
    if(Arr[low]<=Arr[high])
        return  low;
    LL mid=(low+high)/2;
    if(Arr[(mid+1)%N]>=Arr[mid]&&Arr[(mid-1+N)%N]>=Arr[mid])
        return mid;
    else if(Arr[mid]<=Arr[high])
        return RotatedArray(Arr,low,mid-1,N);
    else
        return RotatedArray(Arr,mid+1,high,N);
}

int main()
{
    LL Arr[]={1,2,3,4,5,6,7};
    cout<<RotatedArray(Arr,0,sizeof(Arr)/sizeof(Arr[0])-1,sizeof(Arr)/sizeof(Arr[0]))<<endl;
    LL A[]={12,13,14,16,17,18,2,4,5};
    cout<<RotatedArray(A,0,sizeof(A)/sizeof(A[0])-1,sizeof(A)/sizeof(A[0]))<<endl;
    return 0;

}
