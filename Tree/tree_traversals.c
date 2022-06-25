#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

Node* get_node(int data);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void levelorder(Node *root);
 
int main()
{
    Node *root = NULL;
    root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->right->left = get_node(6);
    root->right->right = get_node(7);

    preorder(root); printf("\n");
    inorder(root); printf("\n");
    postorder(root); printf("\n");
    levelorder(root); printf("\n");
    return 0;
}

Node* get_node(int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
}

void preorder(Node *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    if(root->left)
        preorder(root->left);
    if(root->right)
        preorder(root->right);
}

void inorder(Node *root)
{
    if(root == NULL)    return;
    if(root->left)
        inorder(root->left);
    printf("%d ", root->data);
    if(root->right)
        inorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)    return;
    if(root->left)
        postorder(root->left);
    if(root->right)
        postorder(root->right);
    printf("%d ", root->data);
}

void levelorder(Node *root)
{
    if(root == NULL)    return;
    Queue Q;
    init_queue(&Q, 10);
    enqueue(&Q, root);
    while(!isEmpty(&Q))
    {
        root = dequeue(&Q);
        printf("%d ", root->data);
        if(root->left)
            enqueue(&Q, root->left);
        if(root->right)
            enqueue(&Q, root->right);
    }
}