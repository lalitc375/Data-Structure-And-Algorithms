#include<bits/stdc++.h>
using namespace std;
//Check The Edit Distance Is 1
bool oneAway(string first,string second)
{
    if(first.length()==second.length())
    {   //cout<<"L";
        int len=first.length();
        int i=0,j=0;
        bool sig=false;
        for(i=0;i<len;++i)
        {
            if((first[i]!=second[i])&&!sig)
                sig=true;
            else if(first[i]!=second[i])
                return false;
        }

    }
    else if(abs(first.length()-second.length())==1 ||abs(second.length()-first.length())==1)
    {
        //cout<<"A";
        if(first.length()<second.length())
        {
            string temp;
            temp=second;
            second=first;
            first=temp;
            int i=0,j=0,len=second.length();
            bool sig=true;
            while(j<len)
            {
                if((first[i]!=second[j])&&sig)
                   {
                    ++i;
                    sig=false;
                   }
                else if(first[i]!=second[j])
                    return false;
                else
                {
                    ++i;
                    ++j;
                }
            }

        }
    }
    else
    {

       return false;

    }

    return true;
}
int main()
{
    string f="Lalit Chauhan",s="LalitChauhan";
    cout<<oneAway(s,f);
    return 0;
}
