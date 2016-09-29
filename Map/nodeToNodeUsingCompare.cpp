#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
{
    LL id;
    string str;
};
class nodeCompare
{
public:
    bool operator()(const node &a,const node &b)
    {
        if(a.str==b.str)
            return a.id>b.id;

        return a.str<b.str;
    }
};
int main()
{
    map <node,LL,nodeCompare> mp;
    node a,b,c;
    a.id=1;
    a.str="Lalit";
    b.id=0;
    b.str="Salit";
    c.id=1;
    c.str="Rohit";
    mp[a]=10;
    mp[b]=20;
    mp[c]=30;
    map <node,LL,nodeCompare> ::  iterator itr;
    itr=mp.begin();
    while(itr!=mp.end())
    {
        cout<<((*itr).first).id<<" "<<((*itr).first).str<<" "<<(*itr).second<<endl;
        ++itr;
    }
    return 0;
}
