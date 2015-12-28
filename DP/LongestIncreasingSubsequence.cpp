#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL LongestIncreasingSubsequence(LL Arr[],LL size1)
{
    LL max1,i,j;
    vector<LL> LIS(size1,1);

    for(i=1;i<size1;++i)
    {
        for(j=0;j<i;++j)
        {
            if(Arr[j]<Arr[i]&&LIS[i]<=(LIS[j]+1))
                LIS[i]=LIS[j]+1;
        }
        max1=max(max1,LIS[i]);
    }
    return max1;
}
int main()
{
    LL Arr[]={1,2,3,4};
    cout<<LongestIncreasingSubsequence(Arr,sizeof(Arr)/sizeof(LL));
    return 0;
}
