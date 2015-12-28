//average complexity nlog(n)
//space complexity n
//Quicksort
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int k;
    k=*a;
    *a=*b;
    *b=k;
}

int partition(int arr[],int l,int h) // Partition Function to place Pivot Function at thier Postion
{
    int pivot=l; //Let First Element as Pivot
    int left=l;
    int right=h;
    while(left<right)
    {
    while(arr[right]>arr[pivot]) //searching smaller element at right side of array
        --right;
    swap(&arr[right],&arr[pivot]);
    pivot=right;
    if(left>right)
        break;
    while(arr[left]<arr[pivot]) //searching greater element at left side of array
        ++left;

        swap(&arr[left],&arr[pivot]);
        pivot=left;
    }

    return pivot;
}
int Partition(int arr[],int l,int h) //According to clsrs Book
{
    int i=l-1;
    int j=l;
    int x=arr[h]; //Pivot element
    for(j=l;j<=h-1;++j)
        {
        if(arr[j]<x)
            {
            i=i+1;
            swap(&arr[j],&arr[i]);  //Place smallest ement at begining of array
            }
        }
    swap(&arr[i+1],&arr[h]); //Swap Last Element and to corresponding povit position
    return i+1;
}
void quicksort(int arr[],int l,int h)
{
    //cout<<"t";
    if(l+1>=h)
        return;
    int p=Partition(arr,l,h);
    quicksort(arr,l,p-1); //Left subarray
    quicksort(arr,p+1,h); //right subarray

}
void printarray(int arr[],int l,int h) //Utility Function
{
    for(int i=l;i<=h;++i)
        cout<<arr[i]<<'\t';
}
int main() //Driver Function
{
    //cout<<'L';
    int A[]={25,12,13,45,16,100,36,10,20,30,100,200,0,-100};
    quicksort(A,0,13);
    printarray(A,0,13);
    return 0;

}


