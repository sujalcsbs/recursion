#include "queue.h"

void init(queue *Q, int size)
{
    Q->size = size;
    Q->front = Q->rear = -1;
    Q->arr = (ITEM *)malloc(sizeof(ITEM) * size);
}

int isEmpty(queue *Q)
{
    return (Q->front == -1);
}

int isFull(queue *Q)
{
    return (Q->front == 0 && Q->rear == Q->size-1 || Q->rear+1 == Q->front);
}

int enqueue(queue *Q, ITEM data)
{
    if(isFull(Q))
        return 0;
    if(Q->front == -1)
        Q->front = 0;
    if(Q->rear == Q->size-1)
        Q->rear = -1;
    Q->arr[++(Q->rear)] = data;
    return 1;
}

void display(queue *Q)
{
    while(Q->front <= Q->rear)
    {
        printf("%d ", Q->arr[Q->front]);
        Q->front++;
    }
    printf("\n");
}

ITEM dequeue(queue *Q)
{
    if(isEmpty(Q))
        return;
    return Q->arr[Q->front++];
}
