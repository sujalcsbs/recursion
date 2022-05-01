#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;



node *create(int data);
void append(node **head, int data);
void traverse(node *head);
int delete(node **head, int node_number);
int add_node_at(node **head, int node_number, int data);
int add_node_after(node **, int node_number, int data);
int add_node_before(node **head, int node_number, int data);