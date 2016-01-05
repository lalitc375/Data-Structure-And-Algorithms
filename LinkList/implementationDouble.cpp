#include<bits/stdc++.h>
using namespace std;
struct DoubleLinkNode
{
    int data;
    struct DoubleLinkNode  * next,*prev;
};
void pushDoubleLink(struct DoubleLinkNode **headref,int data)
{
    struct DoubleLinkNode * temp= new(struct DoubleLinkNode);
    temp->next=*headref;
    temp->prev=NULL;
    temp->data=data;
    *headref=temp;
}
void appendDoubleLink(struct DoubleLinkNode *headref,int data)
{
    while(headref->next!=NULL)
        headref=headref->next;
    struct DoubleLinkNode * temp= new(struct DoubleLinkNode);
    headref->next=temp;
    temp->prev=temp;
    temp->data=data;
}
void PrintDoubleLink(struct DoubleLinkNode *headref)
{
    while(headref!=NULL)
    {
        printf("%d ",headref->data);
        headref=headref->next;
    }
    printf("\n");
}
int main()
{
    struct DoubleLinkNode *head =new(struct DoubleLinkNode);
    head->data=5;
    head->next=head->prev=NULL;
    pushDoubleLink(&head,6);
    for(int i=3;i<10;++i)    pushDoubleLink(&head,i);
    appendDoubleLink(head,0);
    for(int i=3;i<10;++i)    appendDoubleLink(head,i*5);

    PrintDoubleLink(head);
    return 0;
}
