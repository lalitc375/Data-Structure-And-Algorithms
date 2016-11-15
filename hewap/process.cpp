#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
    {
        LL time;
        LL duration;
    };
bool compare(const node &a,const node &b)
    {
        if(a.time==b.time)
            {
                return a.duration<=b.duration;
            }
        return a.time<b.time;
    }
class comparison
{
public:
    bool operator() (const node &a ,const node &b)
    {
        return a.duration>b.duration;
    }

};

int main() {
    LL N,i,j,k,current;
    scanf("%lld",&N);
    vector<node> arr(N);
    for(i=0;i<N;++i)
        {
            scanf("%lld %lld",&arr[i].time,&arr[i].duration);
        }
    sort(arr.begin(),arr.end(),compare);
    priority_queue<node,vector<node>,comparison> pr;
    current=0;
    i=0;
    node a;
    LL sum=0;
    while(1)
        {
           while(i<N&&arr[i].time<=current)
               {
                pr.push(arr[i]);
                ++i;
                }
            if(pr.empty()&&i<N)
                {
                    current=arr[i].time;
                    pr.push(arr[i]);
                    ++i;
                }
            if(pr.empty()&&i==N)
                {
                    break;
                }
            a=pr.top();
            pr.pop();
           // cout<<current<<" "<<a.time<<endl;
            sum+=(current-a.time+a.duration);
            current+=a.duration;
        }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        cout<<sum/N;
    return 0;
}

