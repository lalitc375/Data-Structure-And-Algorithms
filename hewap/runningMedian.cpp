#include<bits/stdc++.h>
#define LL long long
using namespace std;
class camparison
{
public:
    bool operator() (LL &a,LL&b)
    {
        return a>b;
    }

};

struct node
{
    int a;
    int b;
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    priority_queue<LL> maxHeap;
    priority_queue<LL,vector<LL>,camparison> minHeap;
    LL N,i,j,k,balance,ele;
    scanf("%lld",&N);
    while(N--)
        {
            scanf("%lld",&ele);

            if((!minHeap.empty()&&minHeap.top()<=ele)||(!maxHeap.empty()&&maxHeap.top()<=ele))
                {
                    minHeap.push(ele);
                }
            else if((!maxHeap.empty()&&maxHeap.top()>=ele)||(!minHeap.empty()&&minHeap.top()>=ele))
                {
                    maxHeap.push(ele);
                }
            else
            {
                minHeap.push(ele);
            }


            if(abs(minHeap.size()-maxHeap.size())>=2)
                {
                    if(minHeap.size()>maxHeap.size())
                        {
                            maxHeap.push(minHeap.top());
                            minHeap.pop();
                        }
                else
                    {
                        minHeap.push(maxHeap.top());
                            maxHeap.pop();
                    }
                }
            //cout<<minHeap.size()<<" "<<maxHeap.size()<<endl;
           long double first,second;
           if(minHeap.size()==maxHeap.size())
               {
                    first=minHeap.top();
                    second=maxHeap.top();
                    printf("%.1Lf\n",(first+second)/2);
               }
            else if(minHeap.size()>maxHeap.size())
               {
                    first=minHeap.top();
                    printf("%.1Lf\n",first);
               }
            else
                {
                    first=maxHeap.top();
                    printf("%.1Lf\n",first);
                }
        }
    return 0;
}

