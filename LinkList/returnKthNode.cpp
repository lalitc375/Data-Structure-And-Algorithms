#include<bits/stdc++.h>
using namespace std;
struct linkNode                 //Structure of Node
{
    int Data;
    struct linkNode * next;
};
//Complexity O(K) and Space O(1)
struct linkNode * kThNode(struct linkNode * head,int k)    //Kth Node from starting
{
    int i;
    if(k<=0)
        return NULL;
    if(k==1)
        return head;
    for(i=1;i<k;++i)
    {
        if(head->next)
            head=head->next;
        else
            return NULL;
    }
    return head;
};
//Complexity O(n) and Space O(1)
struct linkNode * kThNodeFromEnd(struct linkNode * head,int k)      //Kth Node from end
{
    struct linkNode * temp=head;
    int i;
    for(i=1;i<k;++i)                //Move K Node Ahead;
    {
        if(temp->next)
            temp=temp->next;
        else
            return NULL;
    }
    while(temp->next)
    {
        head=head->next;
        temp=temp->next;
    }
    return head;
}
//Time Complexity O(n)
//Space Complexity O(1)
void append(struct linkNode **head,int data)
{
    if(!(*head))
    {
        (*head)=(struct linkNode *) malloc(sizeof(struct linkNode));
        (*head)->Data=data;
        (*head)->next=NULL;
        return;
    }
    struct linkNode * temp=(*head);
    while(temp->next)
        temp=temp->next;
    temp->next=(struct linkNode *) malloc(sizeof(struct linkNode));
    temp->next->Data=data;
    temp->next->next=NULL;
}

int main()
{
    struct linkNode * head= (struct linkNode *) malloc(sizeof(struct linkNode));
    head->Data=5;
    append(head,1);
    append(head,2);
    append(head,3);
    append(head,4);
    append(head,5);
    struct linkNode * temp= kThNode(head,4);
    cout<<temp->Data<<endl;
    temp=kThNodeFromEnd(head,3);
    cout<<temp->Data;
    return 0;
}
