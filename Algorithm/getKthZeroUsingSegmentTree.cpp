#include<bits/stdc++.h>
#define LL long long
#define limit  1000
using namespace std;
LL makeSegemenTree(LL Arr[],LL segTree[],LL low,LL high,LL si)
{
    if(low==high)
    {
        if(Arr[low]==0)
            segTree[si]=1;
        else
            segTree[si]=0;
        return segTree[si];
    }
    LL mid=(high+low)/2;
    segTree[si]=makeSegemenTree(Arr,segTree,low,mid,2*si+1)+makeSegemenTree(Arr,segTree,mid+1,high,2*si+2);
    return segTree[si];
}
LL getKth(LL segTree[],LL low,LL high,LL si,LL k)
{
    if(low==high)
        return low;
    if(segTree[si]<k)
        return -1;
    LL mid=(low+high)/2;
    if(segTree[2*si+1]>=k)
        return getKth(segTree,low,mid,2*si+1,k);
    else
        return getKth(segTree,mid+1,high,2*si+2,k-segTree[2*si+1]);
}
LL update(LL arr[],LL segTree[],LL low,LL high,LL si,LL updateIndex,LL updatedValue)
{
    if(low==high)
    {
        arr[updateIndex]=updatedValue;
        if(arr[updateIndex]==0)
            segTree[si]=1;
        else
            segTree[si]=0;
        return segTree[si];
    }
    LL mid=(low+high)/2;
    if(updateIndex<=mid)
        segTree[si]=update(arr,segTree,low,mid,2*si+1,updateIndex,updatedValue)+segTree[2*si+2];
    else
        segTree[si]=segTree[2*si+1]+update(arr,segTree,mid+1,high,2*si+2,updateIndex,updatedValue);
    return segTree[si];
}
int main()
{
    LL arr[limit];
    LL segTree[4*limit+5];
    arr[0]=0;
    arr[1]=1;
    arr[2]=0;
    arr[3]=0;
    arr[4]=4;
    makeSegemenTree(arr,segTree,0,10,0);
    cout<<getKth(segTree,0,10,0,2)<<endl;
    update(arr,segTree,0,10,0,2,5);
    update(arr,segTree,0,10,0,1,0);
    cout<<arr[2]<<endl;
    cout<<getKth(segTree,0,10,0,2)<<endl;
    return 0;
}
