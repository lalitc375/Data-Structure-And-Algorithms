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
//Complexity O(K) and Space O(1)
void deleteKThNode(struct linkNode **head,int k)
{
    int i;
    struct linkNode *temp=(*head),*temp1;
    if(k<=0)
        return ;
    if(k==1)
        {
            temp=(*head);
            (*head)=(*head)->next;
            free(temp);
            return ;
        }

    for(i=1;i<k-1;++i)
    {
        if(temp->next)
            (temp)=(temp)->next;
        else
            return;
    }
    if(temp->next)
    {
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    }
}
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
void deletekThNodeFromEnd(struct linkNode * head,int k)      //Kth Node from end
{
    struct linkNode * temp=head;
    int i;
    for(i=1;i<(k-1);++i)                //Move K Node Ahead;
    {
        if(temp->next)
            temp=temp->next;
        else
            return ;
    }

    while(temp->next)
    {
        head=head->next;
        temp=temp->next;
    }
   // cout<<"second Loop Completed"<<endl;
    temp=head->next;
    head->next=head->next->next;
    free(temp);
    return ;
}

//Time Complexity O(n)
//Space Complexity O(1)
void append(struct linkNode * head,int data)
{
    if(!head)
    {
        head=(struct linkNode *) malloc(sizeof(struct linkNode));
        head->Data=data;
        head->next=NULL;
        return;
    }
    while(head->next)
        head=head->next;
    head->next=(struct linkNode *) malloc(sizeof(struct linkNode));
    head->next->Data=data;
    head->next->next=NULL;
}
void Traversing(struct linkNode * head)
{
    while(head)
    {
        cout<<head->Data<<" ";
        head=head->next;
    }
    cout<<"\n";
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

    struct linkNode * temp= kThNode(head,3);
    cout<<temp->Data<<endl;
    temp=kThNodeFromEnd(head,3);
    cout<<temp->Data<<endl;
    Traversing(head);
    deleteKThNode(&head,4);
    Traversing(head);
    //temp= kThNode(head,4);
    //cout<<temp->Data<<endl;
    //temp=kThNodeFromEnd(head,3);
    //cout<<temp->Data<<endl;
    deletekThNodeFromEnd(head,3);
    Traversing(head);
    //temp=kThNodeFromEnd(head,3);
    //cout<<"Lalit Chauhan"<<endl;

    //cout<<temp->Data<<endl;

    return 0;
}

