#include "circular_ll_header.h"

int main()
{
    node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}