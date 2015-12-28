//Multiplication of A and B using Recursion
#include<iostream>
using namespace std;
long int multiply(long int A,long int B)
{
    if(B==0)
        return 0;
    else if(B<0)
        return -1*A+-1*multiply(A,(-1)*B-1);
    else
        return A+multiply(A,B-1);
}
int main()
{
    cout<<multiply(-10,20)<<'\n';
    cout<<multiply(10,-20)<<'\n';
    cout<<multiply(-10,-20)<<'\n';
    cout<<multiply(5,20);
    return 0;
}
