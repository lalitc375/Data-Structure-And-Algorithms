//Link list of three node
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

int main()
    {
    struct node * first,* second,* third;
    first= (struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    first->data=1;
    first->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    return 0;

    }
