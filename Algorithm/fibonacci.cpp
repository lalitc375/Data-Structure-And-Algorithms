#include<iostream>
using namespace std;
int fibonacci(int n)
{
    if(n==1)
        return 0;
    else if (n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
void series(int n)
{
    if(n==0)
        return ;
    series(n-1);
    cout<<fibonacci(n)<<endl;

}               
int main()
{
    series(10);
    return 0;
}
