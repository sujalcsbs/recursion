#include "queue.h"

void init_queue(Queue *Q, int size)
{
    Q->size = size;
    Q->arr = (ITEM *)malloc(sizeof(ITEM) * size);
    Q->front = Q->rear = -1;
}

int isEmpty(Queue *Q)
{
    return (Q->front == -1);
}

int isFull(Queue *Q)
{
    return ((Q->front == 0 && Q->rear == Q->size-1) || (Q->front == Q->rear+1));
}

void enqueue(Queue *Q,  ITEM data)
{
    if(isFull(Q))   return;
    if(Q->front == -1)
        Q->front = Q->rear = 0;
    else if(Q->rear == Q->size-1)
        Q->rear = 0;
    else
        ++Q->rear;
    Q->arr[Q->rear] = data;
}

ITEM dequeue(Queue *Q)
{
    if(isEmpty(Q))  return Empty_queue_return_value;
    ITEM temp = Q->arr[Q->front];
    if(Q->front == Q->rear) 
        Q->front = Q->rear = -1;
    else if(Q->front == Q->size-1)
        Q->front = 0;
    else
        Q->front++;
    return temp;
}

