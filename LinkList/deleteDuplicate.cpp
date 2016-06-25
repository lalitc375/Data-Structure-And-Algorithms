#include<bits/stdc++.h>
using namespace std;
struct linkNode                 //Structure of Node
{
    int Data;
    struct linkNode * next;
};
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

//Remove Duplicate with O(n) with auxiliary Array
void removeDuplicate(struct linkNode * head)
{
    map<int,int>M;
    M[head->Data]=1;
    struct linkNode * temp;
    while(head->next)
    {
        if(M[head->next->Data])
        {
            temp=head->next;
            head->next=head->next->next;
            free(temp);
        }
        else
        {
            M[head->next->Data]=1;
            head=head->next;
        }
    }
}
void removeDuplicateWithOutAuxiliary(struct linkNode * head)
{
    struct linkNode * temp1,*temp2,*temp3;
    temp1=head;
    while(temp1)
    {
        temp2=temp1;
        while(temp2->next)
        {
            if((temp2->next->Data)==temp1->Data)
            {
                temp3=temp2->next;
                temp2->next=temp2->next->next;
                free(temp3);
            }
            else
                temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void traversing(struct linkNode * head)
{
    while(head)
    {
        printf("%d ",head->Data);
        head=head->next;
    }
}
int main()
{
    struct linkNode * head;
    append(&head,5);
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,6);
    append(&head,5);
    append(&head,6);
    append(&head,5);
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,6);
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
    traversing(head);
    cout<<endl;
    //removeDuplicate(head);
    removeDuplicateWithOutAuxiliary(head);
    traversing(head);
    return 0;
}
