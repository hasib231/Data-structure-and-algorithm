#include<stdio.h>

#define q_size 5

typedef struct{
    int data[q_size+1];
    int head,tail;
    }queue;

void enqueue(queue *q,int item)
{
    if(((q->tail+1)%(q_size+1))==q->head)
    {
        printf("Queue is full\n");
        return;
    }
    q->data[q->tail]=item;
    printf("item=%d ",q->data[q->tail]);
    q->tail=(q->tail+1)%(q_size+1);
}

int dequeue(queue *q)
{
    if(q->tail==q->head)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item=q->data[q->head];
    q->head=(q->head+1)%(q_size+1);

    return item;
}

int main()
{
    queue q;
    int item;

    q.head=0;
    q.tail=0;

    enqueue(&q,11);
    printf("tail=%d\n",q.tail);
    enqueue(&q,12);
    printf("tail=%d\n",q.tail);
    enqueue(&q,13);
    printf("tail=%d\n",q.tail);
    enqueue(&q,14);
    printf("tail=%d\n",q.tail);
    enqueue(&q,15);
    printf("tail=%d\n",q.tail);
    enqueue(&q,16);
    printf("tail=%d\n",q.tail);

    printf("beginning head = %d\n",q.head);
    item=dequeue(&q);
    printf("item=%d head=%d\n",item,q.head);
    item=dequeue(&q);

    enqueue(&q,20);
    printf("tail=%d head=%d\n",q.tail,q.head);

    printf("item=%d head=%d\n",item,q.head);
    item=dequeue(&q);
    printf("item=%d head=%d\n",item,q.head);
    item=dequeue(&q);
    printf("item=%d head=%d\n",item,q.head);
    item=dequeue(&q);
    printf("item=%d head=%d\n",item,q.head);
    item=dequeue(&q);
    printf("item=%d head=%d\n",item,q.head);

}
