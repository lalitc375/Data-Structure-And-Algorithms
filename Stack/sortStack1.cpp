#include<bits/stdc++.h>
using namespace std;

void insertInSortedStack(stack<int> &Stack,int element);
void sortStack(stack<int> &Stack)
{
    if(Stack.empty())
        return;
    int temp= Stack.top();
    Stack.pop();
    sortStack(Stack);
    insertInSortedStack(Stack,temp);        //Insert in sortedArray
}
void insertInSortedStack(stack<int> &Stack,int element)
{
    if(Stack.empty())
        {
            Stack.push(element);
            return;
        }
    int temp=Stack.top();
    if(temp<element)
        Stack.push(element);
    else
    {
        Stack.pop();
        insertInSortedStack(Stack,element);
        Stack.push(temp);
    }
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(6);
    st.push(10);
    sortStack(st);
    while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    return 0;
}
