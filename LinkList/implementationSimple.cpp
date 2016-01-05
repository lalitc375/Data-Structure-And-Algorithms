#include<bits/stdc++.h>
using namespace std;

struct SimpleLinkNode
{
    int data;
    struct SimpleLinkNode  * next;
};
void push(struct SimpleLinkNode **headref,int data)
{
    struct SimpleLinkNode *temp=new(struct SimpleLinkNode);
    temp->data=data;
    temp->next=*headref;
    *headref=temp;
}
void append(struct SimpleLinkNode *headref,int data)
{
    while(headref->next!=NULL)
        headref=headref->next;

    struct SimpleLinkNode *temp=new(struct SimpleLinkNode);
    headref->next=temp;
    temp->data=data;
    temp->next=NULL;
}

void PrintSimpleLink(struct SimpleLinkNode *headref)
{
    while(headref!=NULL)
    {
        printf("%d ",headref->data);
        headref=headref->next;
    }
    printf("\n");
}
void PrintSimpleLinkRec(struct SimpleLinkNode *headref)
{
    if(headref==NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ",headref->data);
    PrintSimpleLinkRec(headref->next);
}
void reverseSimpleLink(struct SimpleLinkNode **headref)
{
    struct SimpleLinkNode *next=NULL,*current=*headref,*prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *headref=prev;
}

int main()
{
    struct SimpleLinkNode *head =new(struct SimpleLinkNode);
    head->data=5;
    head->next=NULL;
    push(&head,6);
    for(int i=3;i<10;++i)    push(&head,i);
    append(head,0);
    PrintSimpleLink(head);
    PrintSimpleLinkRec(head);
    reverseSimpleLink(&head);
    PrintSimpleLink(head);
    return 0;
}
