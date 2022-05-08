#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create(int data);
void display(node *head);
void append(node **head, int data);
void delete(node **head, int node_value);
void reverse(node **head);