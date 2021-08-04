#include<stdio.h>
#include<stdlib.h>

#define h &head

typedef struct doubly node;

struct doubly{
    int data;
    node *next;
    node *prev;
    };


node *create_node(int item, node *next, node *prev)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=item;
    newnode->next=next;
    newnode->prev=prev;
    return newnode;

}

void prepend(node **head, int item)
{
    node *newnode=create_node(item,*head,NULL);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    (newnode->next)->prev=newnode;
    *head=newnode;

}

void display(node *head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d\n",head->data);

    display(head->next);
}

int main()
{
    node *head=NULL;

    prepend(h,12);
    prepend(h,11);
    prepend(h,10);
    display(head);

}
