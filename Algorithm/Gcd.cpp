#include<bits/stdc++.h>
using namespace std;
long int gcd(long int A,long int B)
{
    if(B==0)
        return A;
    else
        return gcd(B,A%B);
}
int main()
{
    cout<<gcd(90,45)<<endl;
    cout<<__gcd(90,45)<<endl;
    cout<<gcd(50,120)<<endl;
    return 0;
}
