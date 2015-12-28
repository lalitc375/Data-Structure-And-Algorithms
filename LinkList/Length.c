#include<stdio.h>
#include<stdlib.h>
//Length by iterative Method and Recursive Method

struct node
{
    int data;
    struct node * next;
};
void append(int data,struct node * head_ref)
{
    struct node * Node = (struct node *)malloc(sizeof(struct node));
    Node->data=data;
    while(head_ref->next!=NULL)
        head_ref=head_ref->next;
    head_ref->next=Node;
    Node->next=NULL;
}
void print_list(struct node * head_ref)
{
        while(head_ref!=NULL)
            {
            printf("%d ",head_ref->data);
            head_ref=head_ref->next;
            }
}
int lengthitr(struct node * head_ref)
{
    int count=0;
    while(head_ref!=NULL)
        {
        count++;
        head_ref=head_ref->next;
        }
    return count;
}
int lengthrec(struct node * head_ref)
{
    if(head_ref==NULL)
        return 0;
    else
        return 1 + lengthrec(head_ref->next);
}
int main()
{
    struct node * head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    append(2,head);
    append(3,head);
    append(4,head);
    append(5,head);
    append(6,head);
    print_list(head);

    printf("\n%d\n",lengthitr(head));
    printf("\n%d\n",lengthrec(head));
    return 0;
}
