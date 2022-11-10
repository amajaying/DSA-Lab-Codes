// WAP to create a binary tree using linked list by custom input of data and position by user.

// 1. Insert a node 


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
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *current = root;
        struct node *parent = NULL;
        while(1)
        {
            parent = current;
                current = current->left;
                if(current == NULL)
                {
                    parent->left = temp;
                    return;
                }

                current = current->right;
                if(current == NULL)
                {
                    parent->right = temp;
                    return;
                }
        }
    }
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        insert(data);
    }
    printf("Inorder traversal of the tree is: ");
    inorder(root);
    return 0;
}
