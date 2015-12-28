//Factorial of n using Recursion
#include<iostream>
using namespace std;
long int factorial(long int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main()
{
    cout<<factorial(10);
    cout<<'\n'<<factorial(5);
    return 0;
}
