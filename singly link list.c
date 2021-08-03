#include<stdio.h>
#include<stdlib.h>

struct std
{
    int id;
    struct std *next;
}*start=NULL;

void create()
{
    int i,n;
    struct std *newnode,*current;
    printf("How many nodes do u want: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        newnode=(struct std*)malloc(sizeof(struct std));
        printf("Enter the id:");
        scanf("%d",&newnode->id);
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
    }
}


void f_insert()
{
    struct std *newnode,*current;
    newnode=(struct std*)malloc(sizeof(struct std));
    printf("Enter the id for first node: ");
    scanf("%d",&newnode->id);
    newnode->next=NULL;
    if(start==NULL)
    {
        printf("!!Error for there is no link list");
    }
    current=start;
    start=newnode;
    newnode->next=current;
}

void l_insert()
{
    struct std *newnode,*current;
    newnode=(struct std*)malloc(sizeof(struct std));
    printf("Enter the id for last node: ");
    scanf("%d",&newnode->id);
    newnode->next=NULL;
    if(start==NULL)
    {
        printf("!!Error for there is no link list");
    }
    current=start;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;

}

void count()
{
    struct std *current;
    int count=0;
    current=start;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    printf("\nTotal number of nodes: %d\n",count);
}


int search(int s_key)
{
    int pos=0;
    struct std *current;
    current=start;
    while(current!=NULL)
    {
        pos++;
        if(s_key==current->id)
        {
            return pos;

        }
        current=current->next;

    }
    return -1;
}


void ma_insert()
{
    struct std *newnode,*current,*temp;
    int key,pos,i;
    newnode=(struct std*)malloc(sizeof(struct std));
    printf("\nEnter the id for middle (after) node: ");
    scanf("%d",&newnode->id);
    newnode->next=NULL;
    if(start==NULL)
    {
        printf("!!Error for there is no link list");
    }
    printf("\nEnter the value after which the newnode has been insert:");
    scanf("%d",&key);
    pos=search(key);
    current=start;
    for(i=1; i<=pos-1; i++)
    {
        current=current->next;
    }
    printf("\nThe current id is: %d\n",current->id);
    temp=current->next;
    current->next=newnode;
    newnode->next=temp;

}

void mb_insert()
{
    struct std *newnode,*current,*temp;
    int key,pos,i;
    newnode=(struct std*)malloc(sizeof(struct std));
    printf("\nEnter the id for middle (before) node: ");
    scanf("%d",&newnode->id);
    newnode->next=NULL;
    if(start==NULL)
    {
        printf("!!Error for there is no link list");
    }
    printf("\nEnter the value before which the newnode has been insert:");
    scanf("%d",&key);
    pos=search(key);
    current=start;

    for(i=1; i<=pos-2; i++)
    {
        current=current->next;
    }
    printf("\nThe current id is: %d\n",current->id);
    temp=current->next;
    current->next=newnode;
    newnode->next=temp;

}
void delete(int d_key)
{
    struct std *current,*temp1,*temp2,*temp;
    int pos,i;
    pos=search(d_key);
    current=start;
    for(i=1; i<=pos-1; i++)
    {
        current=current->next;
    }
    printf("\nThe current id is:%d\n",current->id);
    if(current==start)
    {
        start=current->next;
    }
    else if(current->next==NULL)
    {
        temp=start;
        for(i=1; i<=pos-2; i++)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    else
    {
        temp=start;
        for(i=1; i<=pos-2; i++)
        {
            temp=temp->next;
        }
        temp1=temp;
        temp=temp->next;
        temp=temp->next;
        temp2=temp;
        temp1->next=temp2;
    }
    printf("\n%d is successfully deleted.\n",d_key);

}


void display()
{
    struct std *current;
    printf("The created link list is:\n");
    current=start;
    while(current!=NULL)
    {
        printf("%d-->",current->id);
        current=current->next;
    }
    printf("NULL\n");

}

int main()
{
    int s_key,pos,d_key;
    create();
    display();

    f_insert();
    display();

    l_insert();
    display();

    count();

    ma_insert();
    display();
    count();
    mb_insert();
    display();
    count();


    for(int i=1; i<=3; i++) // it will delete 3 times
    {
        printf("\nEnter the data you want to delete: ");
        scanf("%d",&d_key);
        delete(d_key);
        display();
        count();
    }

    return 0;
}
