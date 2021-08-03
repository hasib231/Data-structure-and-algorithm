#include<stdio.h>

typedef struct std node;

struct std
{
    int data;
    node *next;
}*head=NULL;



void create_node()
{
    int i,n;
    node *newnode, *current;

    printf("How many nodes do you create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the %d no data: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;

        }
    }
}




void display()
{
    node *current;
    current=head;
    while(current!=NULL)
    {
        printf("%d-->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void first_insert()
{
    node *newnode,*current;

    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data for first node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        printf("!!Error for here is no link list\n");
    }

    current=head;
    head=newnode;
    newnode->next=current;

}




void last_insert()
{
    node *newnode,*current;

    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data for last node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        printf("!!Error for here is no link list\n");
    }

    current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
}




void count()
{
    node *current;
    int count=0;
    current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    printf("\nTotal number of nodes: %d\n",count);
}

int search(int key)
{
    int pos=0;
    node *current;
    current=head;
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




void middle_after_insert()
{
    node *newnode,*current,*temp;
    int key,pos,i;

    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data for middle (after) node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        printf("!!Error for there is no link list");
    }
    else
    {
        printf("\nEnter the data,where you insert new data after: ");
        scanf("%d",&key);
        pos=search(key);

        current=head;
        for(i=0; i<pos-1; i++)
        {
            current=current->next;
        }
        printf("\nThe current data is: %d\n",current->data);

        temp=current->next;
        current->next=newnode;
        newnode->next=temp;

    }

}





void middle_before_insert()
{
    node *newnode,*current,*temp;
    int key,pos,i;

    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data for middle (before) node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        printf("!!Error for there is no link list");
    }
    else
    {
        printf("\nEnter the data,where you insert new data before: ");

    scanf("%d",&key);
    pos=search(key);
    current=head;

    for(i=0; i<pos-2; i++)
    {
        current=current->next;
    }
    printf("\nThe current data is: %d\n",current->data);

    temp=current->next;
    current->next=newnode;
    newnode->next=temp;
    }

}





void delete(int d_key)
{
    node *current, *temp, *temp1;
    int pos,i;
    pos=search(d_key);
    current=head;

    for(i=0; i<pos-1; i++)
    {
        current=current->next;
    }

    printf("\nThe current data is:%d\n",current->data);

    if(current==head)
    {
        head=current->next;
    }

    else if(current->next==NULL)
    {
        temp=head;
        for(i=0; i<pos-2; i++)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }

    else
    {
        temp=head;

        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }

        temp1=temp;
        temp=temp->next;
        temp=temp->next;
        temp1->next=temp;

    }
    printf("\n%d is successfully deleted.\n",d_key);

}




int main()
{
    int i,d_key;

    create_node();
    display();
    count();

    first_insert();
    display();

    last_insert();
    display();

    middle_after_insert();
    display();

    middle_before_insert();
    display();

    for(int i=0; i<3; i++) // it will delete 3 times
    {
        printf("\nEnter the data you want to delete: ");
        scanf("%d",&d_key);
        delete(d_key);
        display();
        count();
    }

    return 0;

}
