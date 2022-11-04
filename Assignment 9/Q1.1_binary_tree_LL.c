// WAP to create a binary tree using linked list.

// 1. Insert a node 

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
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        struct node *temp = root;
        while (1)
        {
            if (temp->left == NULL)
            {
                temp->left = new_node;
                break;
            }
            else if(temp->left != NULL)
            {
                temp = temp->left;
            }
            
            else if (temp->right == NULL)
            {
                temp->right = new_node;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

void traverse(struct node *temp)
{
    if (temp != NULL)
    {
        traverse(temp->left);
        printf("%d ", temp->data);
        traverse(temp->right);
    }
}
int main()
{
    int i, j, k, l, m, n, choice, data;
    while (1)
    {
        printf("1.Insert a node\n2.Print Tree\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert(data);
            break;

        case 2:
            printf("The elements are: \n");
            traverse(root);
            printf("\n\n");
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}

