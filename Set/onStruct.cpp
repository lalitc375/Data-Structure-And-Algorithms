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
            return a.id<b.id;
        return a.str<b.str;
    }
};

int main()
{
    set<node,nodeCompare> st;
    set<node,nodeCompare> :: iterator itr;
    node a,b,c;
    a.id=0;
    a.str="Lalit";
    b.id=0;
    b.str="Lalit";
    c.id=1;
    c.str="Rohit";
    st.insert(a);
    st.insert(b);
    st.insert(c);
    for(LL i=0;i<10;++i)
    {
        a.id=i;
        a.str="Lalit";
        st.insert(a);
    }
    itr=st.begin();
    while(itr!=st.end())
    {
        node a=*itr;
        cout<<a.id<<" "<<a.str<<endl;
        ++itr;
    }
    return 0;
}
