// WAP to create a Binary Search Tree using array having the following operations:
// 1. Insert a node 2. delete a node 3. traversal search a tree

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
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new_node;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
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
        printf(" 1. Insert a node\n 2. delete a node\n 3. traversal search a tree \n 4. Exit\n");
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
            printf("\n\nSorry! This feature is not available yet\n\n");
            break;

        case 3:
            printf("The elements are: \n");
            traverse(root);
            printf("\n\n");
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}



