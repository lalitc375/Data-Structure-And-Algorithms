#include<stdio.h>
#include<stdlib.h>
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

int main()
{
    struct node * head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    insertion(5,head);
    insertion(4,head);
    insertion(3,head);
    insertion(2,head);
    print_list(head);
    return 0;
}






