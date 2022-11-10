// wAP to search an element in a binary tree

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
            if(data < parent->data)
            {
                current = current->left;
                if(current == NULL)
                {
                    parent->left = temp;
                    return;
                }
            }
            else
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = temp;
                    return;
                }
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

int search(struct node *root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    int n, data, i;
    printf("Enter the number of elements you want to insert in the tree: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }
    printf("Inorder traversal of the tree is: ");
    inorder(root);
    printf("\nEnter the element you want to search: ");
    scanf("%d", &data);
    if(search(root, data) == 1)
    {
        printf("Element found");
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}