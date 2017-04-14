#include<bits/stdc++.h>
using namespace std;
bool generateSmallest(string &str,int i)
{
    if(!str[i])
        return true;
    else if(str[i]!='?')
        return generateSmallest(str,i+1);
    else if(str[i]=='?')
    {
        if(i==0)
        {

        }

    }
}
