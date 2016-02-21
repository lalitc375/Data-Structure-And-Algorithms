#include<bits/stdc++.h>
#define LL long long
using namespace std;



int main()
{
    int W[4][4]={{0,500,5,500},{1,0,2,2},{2,4,0,500},{2,1,1,0}};
    //cout<<W[0][0]<<endl;
    int distance[3],i;
    distance[0]=0;
    distance[1]=INT_MAX;
    distance[2]=INT_MAX;
    distance[3]=INT_MAX;
    int counter=0;
    int visited[4]={0};

    while(counter<4)
    {
        int min1=INT_MAX;
        int min_loc=0;

        for(i=0;i<4;++i)
        {
            if(distance[i]<min1&&visited[i]==0)
            {
                min1=distance[i];
                min_loc=i;
            }
        }
        cout<<min_loc<<endl;
        visited[min_loc]=1;
        for(i=0;i<4;++i)
            distance[i]=min(distance[i],distance[min_loc]+W[min_loc][i]);
        ++counter;
    }
    cout<<distance[0]<<endl;
    cout<<distance[1]<<endl;
    cout<<distance[2]<<endl;
    cout<<distance[3]<<endl;
    return 0;
}
