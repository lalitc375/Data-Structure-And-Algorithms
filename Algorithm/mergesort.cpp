//Space complexity n2
//Time Complexity nlog(n)
#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int h);
void mergesort(int arr[],int l,int h)
{
    if(l>=h)
        return;
    int m;
    m=(l+h)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,h);
    merge(arr,l,m,h);
}
void merge(int arr[],int l,int m,int h)
{
    int n1,n2;
    int i,j,k=l;
    n1=m-l+1;
    n2=h-m;
    int L[n1];
    int R[n2];

    for(i=0;i<n1;++i)
        L[i]=arr[i+l];
    for(j=0;j<n2;++j)
        R[j]=arr[j+m+1];
    i=0,j=0;
    for(k=l;k<=h&&i<n2&&j<n1;++k)
        {
        if(R[i]>=L[j])
            {
            arr[k]=L[j];
            j++;
            }
        else
            {
            arr[k]=R[i];
            i++;
            }
        }
    while(i<n2)
    {
        arr[k]=R[i];
        i++;
        k++;
    }
    while(j<n1)
    {
        arr[k]=L[j];
        j++;
        k++;
    }

    }

void printarray(int arr[],int l,int h) //Utility Function
{
    for(int i=l;i<=h;++i)
        cout<<arr[i]<<'\t';
}
int main() //Driver Funkction
{
    //cout<<'L';
    int A[]={25,12,13,45,16,100,36,10,20,30,100,200,0,-100};
    mergesort(A,0,13);
    printarray(A,0,13);
    return 0;

}
