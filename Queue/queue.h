#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *right, *left;
}Node;
#define ITEM Node*
#define Empty_queue_return_value NULL

typedef struct 
{
    ITEM *arr;
    int front, rear, size;
}Queue;

void init_queue(Queue *queue_name, int size);
int isEmpty(Queue *queue_name);
int isFull(Queue *queue_name);
void enqueue(Queue *queue_name, ITEM data);
ITEM dequeue(Queue *queue_name);