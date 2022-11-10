// Write a C program to implement Level Order Search or Breadth-First Search (BFS).

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

// Breadth-First Search

void bfs(struct node *temp)
{
    if(temp != NULL)
    {
        printf("%d ", temp->data);
        bfs(temp->left);
        bfs(temp->right);
    }
}

int main()
{
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data of nodes: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }
    printf("Breadth-First Search: ");
    bfs(root);
    return 0;
}