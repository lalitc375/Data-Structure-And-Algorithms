#include<vector>
#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

vector<long> Arr[29];
long count1[28];
char B[1000005];
char A[1005];

long binaryRec(vector<long> Arr,long element,long low,long high)
{
    long mid=(low+high)/2;
    if(low>high) //when element not found£
        {
            if(low>=0&&Arr[low] > element)
                return low;
            else
                return -1;
        }
    else if(Arr[mid]==element) //When mid Element is equal to element to be searched
        return mid;
    else if(Arr[mid]>element) //When mid Element is greater than element to be searched
        return binaryRec(Arr,element,low,mid-1);
    else                //When mid Element is smaller than element to be searched
        return binaryRec(Arr,element,mid+1,high);
}


int main()
{

    char c;
    //long Arr[26][100];
    long i=0,j;
    long T;
    long loc=0;
    int flag;
    scanf("%ld",&T);
    long Q;
    long index;
    for(i=1;i<=T;++i)
    {

        for(j=0;j<26;++j) count1[j]=-1;
        printf("Case %ld:\n",i);
        scanf("%s",B);
        j=0;
        while(B[j]!='\0')
            {
                count1[B[j]-'a']++;
                Arr[B[j]-'a'].push_back(j);
                ++j;
            }


        scanf("%ld",&Q);

        while(Q--)
        {
            scanf("%s",A);
            loc=0;flag=0;
            long len=strlen(A);
            for(j=0;j<len;++j)
            {
                if(count1[A[j]-'a']==-1){flag=1; break;}

                index=binaryRec(Arr[A[j]-'a'],loc,0,count1[A[j]-'a']);

                if(index>count1[A[j]-'a']||index==-1)
                 {
                    flag=1;
                    break;
                 }
                 loc=Arr[A[j]-'a'][index];
                ++loc;
            }

            if(flag==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
return 0;
}
