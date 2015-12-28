#include<bits/stdc++.h>
using namespace std;
void computeLPS(char * Patt,int M,int * LPS)
{

    int len=0; //Length of Previous Longest Prefix Suffix
    LPS[0]=0;
    int i=1;
    while(i<M)
    {
        if(Patt[i]==Patt[len])
        {
            ++len;
            LPS[i]=len;
            ++i;
        }

        else
        {
            if(len!=0)
            {
                len=LPS[len-1];
            }
            else
            {
                LPS[i]=0;
                ++i;
            }
        }
    }
}

int main()
{
    long N;
    scanf("%ld",&N);
    string A,B;
    cin>>A;
    cin>>B;
    B+=B;
    cout<<A<<endl;
    cout<<B;
    char * a=(char *)A.c_str();
    char * b=(char *)B.c_str();
    int  M[N+2];
    computeLPS(a,N,M);
    long i=0,j=0;
    while (i < N)
    {
      if (B[j] == A[i])
      {
        j++;
        i++;

      }

      // mismatch after j matches
      else if (i < N && B[j] != A[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = M[j-1];

        else
         i = i+1;
      }
    }

    return 0;

}
