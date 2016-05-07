#include<bits/stdc++.h>
using namespace std;

void sortInsert(stack<int>St,int element)
{
    if(St.empty())
        St.push(element);
    else if(St.top()<=element)
        St.push(element);
    else
    {
        int temp=St.top();
        St.pop();
        sortInsert(St,element);
        St.push(temp);
    }
}

void sortStack(stack<int> St)
{
    if (!St.empty())
        {
        int temp=St.top();
        St.pop();
        sortStack(St);
        sortInsert(St,temp);
        }
}

int main()
{
    stack<int> St;
    St.push(10);
    St.push(15);
    St.push(5);
    St.push(6);
    sortStack(St);
    while(!St.empty())
    {
        cout<<St.top()<<endl;
        St.pop();
    }
    return 0;
}
