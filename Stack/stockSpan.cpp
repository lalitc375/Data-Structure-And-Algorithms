#include<bits/stdc++.h>
#define LL long long
using namespace std;

void calculateSpan(LL Arr[],LL S[],LL n)
{
    stack<LL> st;
    st.push(0);
    S[0]=1;
    LL i=1;
    while(i<n&&!st.empty())
    {
            while(!st.empty()&&Arr[st.top()]<=Arr[i])
                st.pop();

            //cout<<st.top()<<endl;
            S[i]=(st.empty())?(i+1):(i-st.top());
            st.push(i);
            ++i;
    }
}
int main()
{
    LL Arr[]={10,2,25,2},i;
    LL S[4];
    calculateSpan(Arr,S,4);
    for(i=0;i<4;++i)    cout<<S[i]<<" ";
    return 0;
}
