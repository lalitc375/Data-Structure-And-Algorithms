#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//Binary search
int binaryitr(int Arr[],int element,int low,int high)
{
    int pos=-1;
    int _low,_high,_mid;
    _low=low;
    _high=high;
    _mid=(_low+_high)/2;
    while(_low<=_high)
    {
        if(Arr[_mid]==element)
            {
            pos=_mid;
            break;
            }
        else if(Arr[_mid]<element)
            _low=_mid+1;

        else
            _high=_mid-1;
        _mid=(_low+_high)/2;

    }
    return pos;
}
int binaryRec(int Arr[],int element,int low,int high)
{   int mid;
    if(low>high) //whwn element not found
        return -1;
    else if(Arr[mid=(low+high)/2]==element) //When mid Element is equal to element to be searched
        return mid;
    else if(Arr[mid]>element) //When mid Element is greater than element to be searched
        return binaryRec(Arr,element,low,mid-1);
    else                //When mid Element is smaller than element to be searched
        return binaryRec(Arr,element,mid+1,high);
}

int lowerLimit(int Arr[],int element,int low,int high)
{
    int mid;
    while(low<high)
    {
        mid=low+(high-low)/2;
            if(Arr[mid]>=element)
                high=mid;
            else
                low=mid+1;
    }
    if(Arr[low]==element)   return low;
    else    return -1;
}
int upperLimit(int Arr[],int element,int low,int high)
{
    int mid;
    while(low<high)
    {
        mid=low+(high-low+1)/2;
        if(Arr[mid]<=element)
            low=mid;
        else
            high=mid-1;
    }
    if(Arr[high]==element)  return high;
    else    return -1;
}
bool compare(int i,int j){return i<j;}
//Driver Function
int main()
{
    int A[]={10,11,15,16,16,17,17,18,18,18,19,20,25,30};
    cout<<binaryRec(A,13,0,9)<<endl;
    cout<<binaryitr(A,13,0,9)<<endl;
    cout<<binaryRec(A,17,0,9)<<endl;
    cout<<binaryitr(A,19,0,9)<<endl;

    cout<<"Lower Limit"<<lowerLimit(A,18,0,13)<<endl;
    cout<<"Upper Limit"<<upperLimit(A,18,0,13)<<endl;

    cout<<binary_search(A,A+14,11,compare)<<'\n';//Bool function to find wheather a element exist in sorted array
    cout<<upper_bound(A,A+14,18,compare)-A<<'\n';
    cout<<lower_bound(A,A+14,18,compare)-A<<'\n';
    return 0;
}
