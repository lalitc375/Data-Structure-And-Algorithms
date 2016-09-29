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
    set<node,nodeCompare>st;
    set<node,nodeCompare>:: reverse_iterator ritr;
    node a;
    for(LL i=0;i<10;++i)
    {
        a.id=i;
        a.str="Lalit";
        st.insert(a);
    }
     a.id=0;
     a.str="Rohit";
     st.insert(a);
    ritr=st.rbegin();
    while(ritr!=st.rend())
    {
        a=*ritr;
        cout<<a.id<<" "<<a.str<<endl;
        ++ritr;
    }
    return 0;
}
