#include<bits/stdc++.h>

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
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
    // Preprocess the pattern (calculate lps[] array)
    computeLPS(pat, M, lps);
    int i = 0;  // index for txt[]
    printf("%s\n",pat);
    while(i<M)
        printf("%d ",lps[i++]);
    printf("\n");

    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
int main()
{
   char *txt = (char *)"Chaulan lalitlalit";
   char *pat = (char *)"dacbbcbcbcbcdcbbbcbcbcbcbcbcdacbbcbcdcbbbcbcdcbbdcbb";

   KMPSearch(pat, txt);
   return 0;
}

