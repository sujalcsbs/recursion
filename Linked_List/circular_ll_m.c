#include "circular_ll_header.h"

node *create(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *curr = head;
    do
    {
        printf("%d --> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
    return;
}

void append(node **head, int data)
{
    node *new = create(data);
    if (*head == NULL)
    {
        *head = new;
        new->next = *head;
    }
    node *curr = *head;
    while (curr->next != *head)
        curr = curr->next;
    curr->next = new;
    new->next = *head;
}

void delete(node **head, int n)
{
    node *curr = *head, *temp;
    if(*head == NULL){
        return;
    }
    else if(n == 1 && (*head)->next == NULL)
    {
        *head = NULL;
        return;
    }
    else if(n == 1)
    {
        curr->data = curr->next->data;
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    else
    {
        int i = 1;
        for(; i <= n-1; i++)
        {
            curr = curr->next;
            if(curr->next == *head)
                return;
        }
        curr->data = curr->next->data;
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
}

void reverse(node **head)
{
    if (*head == NULL || (*head)->next == *head)
        return;
    node *curr = *head, *prev = NULL, *next = NULL;
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (next != *head);
    curr->next = prev;
    *head = prev;
}

