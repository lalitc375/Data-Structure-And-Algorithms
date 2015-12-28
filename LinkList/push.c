#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void push(int data,struct node ** head_ref)
{
    struct node * Node = (struct node *)malloc(sizeof(struct node));
    Node->data=data;
    Node->next=*(head_ref);
    *head_ref=Node;

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
    head->data=5;
    head->next=NULL;
    push(4,&head);
    push(6,&head);
    push(8,&head);
    print_list(head);
    return 0;
}
