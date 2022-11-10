// Write a C program to create a Binary Tree using linked list. 2. Write a C program to search an element in a Binary Tree. 3. Write a C program to construct a Binary Search Tree from the given elements: 40, 20, 55, 12, 67, 4. 4. Write a C program to do the following operations:
// A) In-order Traversal
// B) Pre-order Traversal
// C) Post-order Traversal

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

void inorder(struct node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

int main()
{
    insert(40);
    insert(20);
    insert(55);
    insert(12);
    insert(67);
    insert(4);
    printf("Preorder Traversal: ");
    preorder(root);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("Postorder Traversal: ");
    postorder(root);
    return 0;
}
