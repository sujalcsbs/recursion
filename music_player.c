#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char *data;
    struct node *next, *prev;
}Node;

Node *create_node(char *data);
void add(Node **head, char *data);
void add_after(Node **head, Node *curr, char *str);
void add_before(Node **head, Node *curr, char *str);
void delete_specific(Node **head, Node *curr);
Node * search_track(Node *head, char *str);
void play(Node *ptr);
void traverse(Node *head);
void sort(Node **head);
void insert_sorted(Node **head, Node *tmp);
void update_file(Node *head, FILE *fp);
void delete_list(Node **head);
 
int main()
{
    char ch, dummy;
    FILE *fp;
    char str[50];
    Node *head = NULL, *curr = NULL;
    fp = fopen("Music.txt", "r");
    while(fgets(str, sizeof(str), fp))
    {
        add(&head, str);
    }


    while(1)
    {
        printf("\nPress S to Start the player.\n");
        printf("Press T to view your entire playlist.\n");
        printf("Press J to jump to a specific track of the player.\n");
        printf("Press N to play the Next track.\n");
        printf("Press P to play the Previous track.\n");
        printf("Press F to play the First track.\n");
        printf("Press L to play the Last Track\n");
        printf("Press E to add a track to your playlist:\n");
        printf("Press A to add a track after an existing track.\n");
        printf("Press B to add a track before an existing track.\n");
        printf("Press R to remove a specific track from the list.\n");
        printf("Press O to Sort the tracks in alphabetical order\n");
        printf("Press Q to exit from the player and save the changes to the file.\n");

        printf("\nEnter your choice : "); scanf("%c%c", &ch, &dummy);
        printf("\n");

        switch(ch)
        {
            case 'T' :
                if(head == NULL)
                    printf("\nYour Playlist is Empty.\n");
                else
                    traverse(head);
                break;
            case 'S' :       
                curr = head;
                (curr != NULL) ? play(curr) : printf("\nThe playlist is Empty.\n");
                break;
            case 'J':
                if(curr == NULL) printf("\nThe playlist is Empty\n");
                printf("Enter the name of the track: ");
                fgets(str, sizeof(str), stdin);
                curr = search_track(head, str);
                if(curr)
                    (curr != NULL) ? play(curr) : printf("\nThe playlist is Empty.\n");
                else
                    printf("\nThe specified track is not present in the list.\n");
                break;
            case 'N' :
                (curr != NULL) ? play((curr = curr->next)) : printf("\nThe playlist is Empty.\n");
                break;
            case 'P' :
                (curr != NULL) ? play((curr = curr->prev)) : printf("\nThe playlist is Empty.\n");
                break;
            case 'F':
                (head != NULL) ? play((curr = head)) : printf("\nThe playlist is Empty.\n");;
                break;
            case 'L' :
                (head != NULL) ? play((curr = head->prev)) : printf("\nThe playlist is Empty.\n");
                break;
            case 'E' :
                printf("Enter the Track you want to add: ");    fgets(str, sizeof(str), stdin);
                insert_sorted(&head, create_node(str));
                update_file(head, fp);
                printf("\nChanges were Successfull\n");
                break;
            case 'A' :
                if(curr == NULL) printf("\nThe playlist is Empty\n");
                printf("\nEnter the name of the existing track: ");   fgets(str, sizeof(str), stdin);
                curr = search_track(head, str);
                if(curr)
                {
                    printf("\nEnter the name of the new track : ");   fgets(str, sizeof(str), stdin);
                    add_after(&head, curr, str);
                }
                else
                {
                    printf("\nThis track does not exist in your list: \n"); 
                }
                update_file(head, fp);
                break;
            case 'B' :
                if(curr == NULL) printf("\nThe playlist is Empty\n");
                printf("\nEnter the name of the existing track: ");   fgets(str, sizeof(str), stdin);
                curr = search_track(head, str);
                if(curr)
                {
                    printf("\nEnter the name of the new track : ");   fgets(str, sizeof(str), stdin);
                    add_before(&head, curr, str);
                }
                else
                {
                    printf("\nThis track does not exist in your list: \n"); 
                }
                update_file(head, fp);
                break;
            case 'R' :
                if(curr == NULL) printf("\nThe playlist is Empty\n");
                printf("\nEnter the name of the track: ");   
                fgets(str, sizeof(str), stdin);
                curr = search_track(head, str);
                if(curr)
                {
                    delete_specific(&head, curr);
                    update_file(head, fp);
                }
                else
                    printf("\nTrack does not exit in the list.\n");
                break;
            case 'O' :
                sort(&head);
                update_file(head, fp);
                break;
            case 'Q' :
                return 0;
            default :
                printf("\nPlease Enter a Valid choice.\n");
        }
    }

    fclose(fp);

    return 0;
}

Node *create_node(char *data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->prev = tmp->next = NULL;
    tmp->data = strdup(data);
    return tmp;
}

void add(Node **head, char *data)
{
    Node *tmp = create_node(data);
    if(*head == NULL)
    {
        tmp->next = tmp;
        tmp->prev = tmp;
        *head = tmp;
        return;
    }
    tmp->prev = (*head)->prev;
    tmp->next = (*head);
    (*head)->prev->next = tmp;
    (*head)->prev = tmp;
}

void play(Node *tmp)
{
    printf("          ===========> Currently Playing- %s\n", tmp->data);
}

void traverse(Node *head)
{
    if(head == NULL)
        return;
    Node *temp = head;
    do
    {
        printf("%s", temp->data);
        temp = temp->next;
    }while(temp != head);
}

Node *search_track(Node *head, char *str)
{
    Node *ref = head;
    if(head == NULL)
        return NULL;
    while(strcmp(str, head->data) != 0)
    {
        head = head->next;
        if(head == ref)
            return NULL;
    }
    return head;
}

void delete_specific(Node **head, Node *curr)
{
    Node *tmp = NULL;
    if(curr == *head && (*head)->next == *head)
    {
        tmp = *head;
        (*head) = NULL;
        free(tmp);
        return;
    }
    else if(curr == (*head))
    {
        tmp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        (*head) = (*head)->next;
        free(tmp);
        return;
    }
    tmp = curr;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(tmp);
}

void add_after(Node **head, Node *curr, char *str)
{
    Node *tmp = create_node(str);
    if(curr == *head)
    {
        tmp->prev = (*head);
        tmp->next = (*head)->next;
        (*head)->next->prev = tmp;
        (*head)->next = tmp;
        return;
    }

    tmp->next = curr->next;
    tmp->prev = curr;
    curr->next->prev = tmp;
    curr->next = tmp;
}
void add_before(Node **head, Node *curr, char *str)
{
    Node *tmp = create_node(str);
    if(curr == *head)
    {
        tmp->next = (*head);
        tmp->prev = (*head)->prev;
        (*head)->prev->next = tmp;
        (*head)->prev = tmp;
        *head = tmp;
        return;         
    }

    tmp->next = curr;
    tmp->prev = curr->prev;
    curr->prev->next = tmp;
    curr->prev = tmp;
}

void sort(Node **head)
{    
    if(*head == NULL || (*head)->next == *head)
        return;
    Node *curr = *head, *new_head = NULL, *tmp = NULL;
    do
    {
        tmp = curr->next;
        insert_sorted(&new_head, create_node(curr->data));
        free(curr);
        curr = tmp;
    }while(curr != *head);

    *head = new_head;
}

void insert_sorted(Node **head, Node *tmp)
{ 
    if(*head == NULL)
    {
        tmp->next = tmp->prev = tmp;
        *head = tmp;
        return;
    }
    else if(strcmp((*head)->data, tmp->data) > 0)
    {
        tmp->prev = (*head)->prev;
        tmp->next = *head;
        (*head)->prev->next = tmp;
        (*head)->prev = tmp;
        (*head) = tmp;
        return;
    }
    Node *curr = (*head);
    while(curr->next != *head && strcmp(curr->next->data, tmp->data) < 0)
    {
        curr = curr->next;
    }

    tmp->next = curr->next;
    tmp->prev = curr;
    curr->next->prev = tmp;
    curr->next = tmp;
}

void update_file(Node *head, FILE *fp)
{
    fp = fopen("Music.txt", "w+");
    fseek(fp, SEEK_SET, 0);
    Node *tmp = head;
    do
    {
        fputs(tmp->data, fp);
        tmp = tmp->next;
    }while(tmp != head);
}



