#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> St;
    St.push_back(5);
    St.push_front(6);
    St.push_back(1);
    St.push_back(3);
    list<int>::iterator It;
    St.
    It=St.begin();
    while(It!=St.end())
    {
        cout<<*It;
        It++;

    }
    St.pop_back();
    St.pop_front();

    return 0;
}
