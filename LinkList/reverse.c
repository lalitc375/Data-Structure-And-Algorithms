#include<stdio.h>
#include<stdlib.h>
//Reversal Of Linklist by Iterative and Recursive Method

struct node
{
    int data;
    struct node * next;
};
void insertion(int data,struct node * prev_node)
{
    struct node * Node = (struct node *)malloc(sizeof(struct node));
    Node->data=data;
    Node->next=prev_node->next;
    prev_node->next=Node;

}
void print_list(struct node * head_ref)
{
        while(head_ref!=NULL)
            {
            printf("%d ",head_ref->data);
            head_ref=head_ref->next;
            }
}
void reverseitr(struct  node ** head_ref)
{
    struct node * prev_node=NULL;
    struct node * current=*head_ref;
   struct  node * next;
   while(current!=NULL)
   {
        next=current->next;
        current->next=prev_node;
        prev_node=current;
        current=next;
   }
   *head_ref=prev_node;
}
void reverserec(struct node ** head_ref)
{
    struct node * head=*head_ref ;
    struct node * rest ;

    if(head==NULL)
        return;
    rest=head->next;
    if(rest==NULL)
        return;
    reverserec(&rest);
    head->next->next=head;
    head->next=NULL;
    *head_ref=rest;

}
 int main()
{
    /* code */
    struct node * head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    insertion(5,head);
    insertion(4,head);
    insertion(3,head);
    insertion(2,head);
    print_list(head);
    printf("\n");
    reverseitr(&head);
    print_list(head);
    printf("\n");
    reverserec(&head);
    print_list(head);
    printf("\n");
    return 0;
}
