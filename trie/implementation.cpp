// Trie Implementation
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;
struct trie
{
    long int words;
    long int prefixs;
    struct trie * children[26];
};
void initialize(struct trie * node)   //Initialisation  of Node
{
    node->words=0;
    node->prefixs=0;
    for(int i=0;i<26;++i)
        node->children[i]=NULL;
}
void addWord(struct trie * node,char * s)  //To add string s
{
    if(s[0]=='\0')
        {
        node->words+=1;
        return;
        }
    else
        {
        node->prefixs+=1;
        char k=s[0];
        if(node->children[k-'a']==NULL)
        {
            node->children[k-'a']= (struct trie *) malloc(sizeof(struct trie));
            initialize(node->children[k-'a']);
        }
        addWord(node->children[k-'a'],s+1);  //Recurence
        }

}
int countWords(struct trie * node,char *s)
{
    if(s[0]=='\0')
        return node->words;
    else if(node->children[s[0]-'a']==NULL)
        return 0;
    else
        return countWords(node->children[s[0]-'a'],s+1);
}
int countPrefix(struct trie * node,char *s)
{
    if(s[0]=='\0')
        return node->prefixs;
    else if(node->children[s[0]-'a']==NULL)
        return 0;
    else
        return countPrefix(node->children[s[0]-'a'],s+1);
}
int main()
{
    struct trie * root;
    root=(struct trie *) malloc(sizeof(struct trie));
    initialize(root);
    char S[]="lalit";
    char prefix[]="l";
    addWord(root,S);
    addWord(root,(char *)"satt");
    addWord(root,(char *)"satt");
    addWord(root,(char *)"satt");
    addWord(root,(char *)"satt");
    addWord(root,(char *)"chauhan");
    cout<<countWords(root,(char *)"satt")<<endl;
    cout<<countPrefix(root,(char *)"cha");
    return 0;
}



