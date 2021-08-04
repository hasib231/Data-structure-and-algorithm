#include<stdio.h>
#include<stdlib.h>

#define h &head
typedef struct list node;

struct list{
    int data;
    node *next;
    };

node *create_node(int item)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=item;
    newnode->next=NULL;
    return newnode;
}


void prepend(node **head,int item)
{
    node *newnode,*temp;
    newnode=create_node(item);

    if(*head==NULL)
    {
        *head=newnode;
        return;
    }


        temp=*head;
        *head=newnode;
        newnode->next=temp;

}
void rev(node **head)
{
    node *current,*head2=NULL,*temp;
    current=*head;


    while(current!=NULL)
    {
        temp=current;
        current=current->next;
        temp->next=head2;
        head2=temp;

    }
    *head=head2;
}

void append(node **head,int item)
{
    node *newnode,*temp;
    newnode=create_node(item);

    temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;

}

int search(int key,node **head)
{
    node *current;
    current=*head;
    int pos=0;
    while(current!=NULL)
    {
        pos++;
        if(key==current->data)
        {
            return pos;
        }
        current=current->next;
    }
    return -1;
}

void middle_after_insert(node **head,int m_value,int item)
{
    node *newnode,*current,*temp;
    int pos,i;
    newnode=create_node(item);

    current=*head;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    pos=search(m_value,head);

    for(i=0;i<pos-1;i++)
    {
        current=current->next;
    }
    temp=current->next;
    current->next=newnode;
    newnode->next=temp;
}

void delete_node(node **head,int value)
{
    node *current,*temp,*temp1;
    int pos,i;
    current=*head;
    if(current==NULL)
    {
        printf("Error!! no node here\n");
    }
    pos=search(value,head);
    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }

    if(current==*head)
    {
        *head=current->next;
    }

    else if(current->next==NULL)
    {
        temp=*head;
        for(i=0; i<pos-2; i++)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }

    else
    {
        temp=*head;

        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }

        temp1=temp;
        temp=temp->next;
        temp=temp->next;
        temp1->next=temp;

    }
    printf("\n%d is successfully deleted.\n",value);

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
    node *head;
    head=NULL;
    prepend(h,11);

    append(h,13);
    append(h,14);
    append(h,15);
    middle_after_insert(h,13,20);
    display(head);
    printf("\n");

    delete_node(h,20);
    display(head);
    printf("\n");

    printf("rev\n");
    rev(h);
    display(head);

}
