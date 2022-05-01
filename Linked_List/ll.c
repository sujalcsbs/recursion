#include "llm.h"
 
int main()
{
    node *head = NULL, *head2 = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    traverse(head);
    if(delete(&head, 3))
        printf("Deletion SuccessFull\n");
    else    
        printf("Deletion Unsuccessfull\n");
    traverse(head);
    if(add_node_at(&head, 3, 30))
        printf("Insertion Successfull\n");
    else    
        printf("insertion Unsucessfull\n");
    traverse(head);
    if(add_node_before(&head, 3, 25))
        printf("Insertion Successfull\n");
    else    
        printf("insertion Unsuccessfull\n");
    traverse(head);
    return 0;
}


