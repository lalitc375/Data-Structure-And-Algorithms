#include<bits/stdc++.h>
using namespace std;
// proof https://www.quora.com/What-is-the-proof-of-correctness-of-Moores-voting-algorithm
int findCandidate(int Arr[],int n)       //Complexity O(n)
{
    int max_index=0,i,count1=1;
    for(i=1;i<n;++i)
    {
        if(Arr[i]==Arr[max_index])
            ++count1;
        else
            --count1;
        if(count1==0)
        {
            max_index=i;
            count1=1;
        }
    }
    return Arr[max_index];
}
int majorityElementUsingMooresVoting(int Arr[],int n)     // complexity O(n)
{
    int candidate=findCandidate(Arr,n),i,counter=0;
    for(i=0;i<n;++i)
        if(candidate==Arr[i])
            ++counter;
    if(counter>n/2)
        return candidate;
    else
        return -1;          //If no element is major Element
}
int main()
{

    int Arr[]={10,5,1,1,1,2,1,1,1,2};
    cout<<majorityElementUsingMooresVoting(Arr,sizeof(Arr)/sizeof(int));
    return 0;
}
