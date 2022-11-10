// WAP to search an element in a binary tree

#include <stdio.h>
#include <stdlib.h>

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

int search(struct node *temp, int data)
{
    if(temp == NULL)
    {
        return 0;
    }
    else if(temp->data == data)
    {
        return 1;
    }
    else if(data < temp->data)
    {
        return search(temp->left, data);
    }
    else
    {
        return search(temp->right, data);
    }
}

int main()
{
    int n, i, data, search_data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }
    printf("Preorder traversal: ");
    preorder(root);
    printf("Enter the element to be searched: ");   
    scanf("%d", &search_data);
    if(search(root, search_data))
    {
        printf("Element found");
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}

