#include<stdio.h>
#include<stdlib.h>
//To add node at end of linklist
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
    printf("%d",head->data);

    return 0;
}
