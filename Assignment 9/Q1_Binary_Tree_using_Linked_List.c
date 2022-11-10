// Write a C program to create a Binary Tree using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct node *temp = root;
        while(1)
        {
            if(data < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = newnode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void preorder(struct node *temp)
{
    if(temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

int main(){
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("Preorder Traversal: ");
    preorder(root);
    return 0;
}


