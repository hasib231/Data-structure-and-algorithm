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

void append(node **head, int item)
{
    node *newnode=create_node(item,NULL,NULL);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    node *current=*head;

    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    newnode->prev=current;
}

void delete_node(node **head, int item)
{
    node *temp,*temp2;
    if((*head)->data==item)
    {
        temp=(*head)->next;
        *head=temp;
        (*head)->prev=NULL;
        return;
    }

    node *current=*head;
    while(current->data!=item)
    {
        current=current->next;
    }


    temp=(current->next)->prev;
    temp2=current->prev;
    (current->prev)->next=current->next;
    temp=temp2;


//    temp=current->prev;
//    temp2=current->next;
//
//    temp->next=temp2;
//    temp2->prev=temp;

    free(current);

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
    append(h,13);
    display(head);

    printf("\nAfter delete\n");
    delete_node(h,12);
    display(head);

}
