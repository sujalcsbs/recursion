#include "llm.h"

node *create(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(node **head, int data)
{
    node *new_node = NULL, *temp = *head;
    new_node = create(data);
    if(temp == NULL){
        *head = new_node;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;

}

void traverse(node *head)
{
    if(head == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }
    while(head != NULL)
    {
        printf(" %d --> ",head->data);
        head = head->next;
    }
    printf("NULL \n");
}

int delete(node **head, int n)
{
    node *curr = *head, *prev;
    if(n == 1)
    {
        *head = curr->next;
        free(curr);
        return 1;
    }
    int i;
    for(i = 1; curr != NULL && i <= n-1; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        return 0;
    prev->next = curr->next;
    free(curr);
    return 1;
}

int add_node_at(node **head, int n, int data)
{
    if(n < 1)
    {
        return 0;
    }
    node *new = create(data);
    if(n == 1)
    {
        new->next = *head;
        *head = new;
        return 1;
    }
    int i;
    node *curr = *head, *prev;
    for(i = 1; curr != NULL && i < n; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        return 0;
    prev->next = new;
    new->next = curr;
    return 1;
}

int add_node_before(node **head, int n, int data)
{
    return add_node_at(head, n-1, data);
}

int add_node_after(node **head, int n, int data)
{
    return add_node_at(head, n+1, data);
}