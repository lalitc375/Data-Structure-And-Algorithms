#include<bits/stdc++.h>
using namespace std;
//By using Pair
int main()
{
    int i,n;
    cout<<"Number of Activities"<<endl;
    cin>>n;
    vector<pair<int,int> >Arr(n);
    for(i=0;i<n;++i)
        cin>>Arr[i].second>>Arr[i].first;           //input
    std::sort(Arr.begin(), Arr.end());              //sorting on the basis of finish time or first element of pair
    cout<<Arr[0].second<<" "<<Arr[0].first<<endl;    //first Activity with minimum finish time
    int last=0;
    for(i=1;i<n;++i)
    {
        if(Arr[i].second<Arr[last].first)
            continue;
        else
        {
            cout<<Arr[i].second<<" "<<Arr[i].first<<endl;
            last=i;
        }
    }


    return 0;

}
