//By lalitc375
#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define loop(i,a,b) for(i=a;i<b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i)
#define pn(n) printf("%d\n",n)
#define pln(n)  printf("%ld\n",n)
#define plln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sl(n) scanf("%ld",&n)
#define sl2(a,b) scanf("%ld %ld",&a,&b)
#define sl3(a,b,c) scanf("%ld %ld %ld",&a,&b,&c)
#define br putchar('\n')
#define MOD 1000000007
#define debug(x) cout << '>' << #x << ':' << x << endl;
inline LL two(LL n) {return (1LL<<n);}
inline LL ones(int n) { LL res = 0; while(n && ++res) n-=n&(-n); return res; }
inline LL last_bit(LL n) {return (n)&(-n);}
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
bool compare(LL i, LL j) {return i<j;};
int main()
{
    stack <LL> Post;
    string A;
    LL i,j,k;
    cin>>A;
    LL len=A.length();
    for(i=0;i<len;++i)
    {
        if(A[i]>='0'&&A[i]<='9')
            Post.push((LL)A[i]-'0');
        else
        {
            if(Post.empty())
            {
                cout<<"Error";
                break;
            }
            else if(A[i]=='+')
            {
             k=Post.top();
             Post.pop();
             j=Post.top();
            Post.pop();
            Post.push((LL)k+j);
            }
            else if(A[i]=='/')
            {
             k=Post.top();
             Post.pop();
             j=Post.top();
            Post.pop();
            Post.push((LL)j/k);
            }
            else if(A[i]=='-')
            {
             k=Post.top();
             Post.pop();
             j=Post.top();
            Post.pop();
            Post.push((LL)-k+j);
            }
            else if(A[i]=='*')
            {
             k=Post.top();
             Post.pop();
             j=Post.top();
            Post.pop();
            Post.push((LL)k*j);
            }
            else if(A[i]=='^')
            {
             k=Post.top();
             Post.pop();
             j=Post.top();
            Post.pop();
            Post.push((LL)pow(j,k));
            }
        }

    }
    cout<<Post.top();
    return 0;
}




