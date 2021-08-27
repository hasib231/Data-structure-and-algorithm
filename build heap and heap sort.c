#include<stdio.h>

int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return i/2;
}
int is_max_heap(int H[],int heap_size)
{
    int i,p;
    for(i=heap_size;i>1;i--){
        p=parent(i);

    //printf("i=%d,p=%d\tH[i]=%d,H[p]=%d\n",i,p,H[i],H[p]);

    if(H[p]<H[i]){
        return 0;
    }
    }
    return 1;
}

void max_heapify(int heap[],int heap_size,int i)
{
    int l,r,largest,t;
    l=left(i);
    r=right(i);

    if(l<=heap_size && heap[l]>heap[i]){
        largest=l;
    }
    else{
        largest=i;
    }

    if(r<=heap_size && heap[r]>heap[largest]){
        largest=r;
    }

    if(largest!=i){
        t=heap[i];
        heap[i]=heap[largest];
        heap[largest]=t;

        max_heapify(heap,heap_size,largest);
    }
}

void build_max_heap(int heap[],int heap_size)
{
    int i;
    for(i=heap_size/2; i>=1; i--){
        max_heapify(heap,heap_size,i);
    }
}

void print_heap(int heap[],int heap_size)
{
    int i;
    for(i=1;i<=heap_size;i++){
        printf("%d ",heap[i]);
        printf("\n");
    }
}

void heap_sort(int heap[],int heap_size)
{
    int i,t;
    for(i=heap_size;i>1;i--){
        t=heap[1];
        heap[1]=heap[i];
        heap[i]=t;

        heap_size-=1;
        max_heapify(heap,heap_size,1);
    }
}

int main()
{
    int heap_size=9,heap1;
    int heap[]={0,10,17,7,1,2,12,19,3,5};

    print_heap(heap,heap_size);

    build_max_heap(heap,heap_size);

    printf("After heapify\n");
    print_heap(heap,heap_size);

    heap1=is_max_heap(heap,heap_size);
    if(heap1==1)
    {
        printf("It is max heap\n");
    }
    else{
        printf("It is not max heap\n");
    }

    printf("After heap sort\n");
    heap_sort(heap,heap_size);
    print_heap(heap,heap_size);
    return 0;
}
