#include<bits/stdc++.h>
using namespace std;
// complexity O(n)
string URLify(string input)
{
   int len=input.length(),i;
    string temp,ans;
    for(i=0;i<len;++i)
        {
            if(input[i]==' ')
            {
                ans+=temp;
                ans+="%20";
                temp="";
            }
            else
                temp+=input[i];
        }
    ans+=temp;
    return ans;
}
int main()
{
    string Input;
    getline(cin,Input);
    cout<<URLify(Input);
    return 0;
}
