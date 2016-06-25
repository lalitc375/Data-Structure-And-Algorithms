#include<bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    if(n>0)
        printBinary(n/2);
    else
        return ;
    printf("%d",n%2);
    //return 0;
}
void printOct(int n)
{
    if(n>0)
        printOct(n/8);
    else
        return ;
    printf("%d",n%8);
}
void printDec(string bin)
{
    int dec=bin[0]-'0',i;
    for(i=1;i<bin.length();++i)
        dec=dec*2+bin[i]-'0';
    cout<<dec;
}
void printOct(string bin)
{
    int noOfInitialDigit=bin.length()%3,i;
    if(noOfInitialDigit!=0)
        printDec(bin.substr(0,noOfInitialDigit));
    for(i=noOfInitialDigit;i<bin.length();i=i+3)
        printDec(bin.substr(i,3));
}
void printHexdec(int n)
{
    if(n>0)
        printHexdec(n/16);
    else
        return ;
    if((n%16)<10)
        cout<<n%16;
    else
        cout<<char('A'+n%16-10);
}
void printHexdec(string bin)
{
    int noOfInitialDigit=bin.length()%4,i,dec;
    if(noOfInitialDigit!=0)
        printDec(bin.substr(0,noOfInitialDigit));
    for(i=noOfInitialDigit;i<bin.length();i=i+4)
        {
            dec=(bin[i]-'0')*8+(bin[i+1]-'0')*4+(bin[i+2]-'0')*2+(bin[i+3]-'0')*1;
            if(dec<10)
                cout<<dec<<endl;
            else
                cout<<(char)('A'+dec-10);
        }
}

int main()
{
    printBinary(4);
    cout<<"\n";
    printDec((string)"10100");
    cout<<"\n";
    printOct((string)"101010");   //Conversion of binary to oct
    cout<<"\n";
    printOct(100); //Conversion of dec to Oct
    cout<<"\n";
    printHexdec(100);
    cout<<"\n";
    printHexdec((string)"11010000");
    return 0;
}
