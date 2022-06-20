#include <stdio.h>
#include <stdlib.h>
#define ITEM int

typedef struct queue
{
    ITEM *arr;
    int rear, front, size;
}queue;

void init(queue *, int);
int isEmpty(queue *);
int isFull(queue *);
int enqueue(queue *, ITEM);
void display(queue *);
void dequeue(queue *);