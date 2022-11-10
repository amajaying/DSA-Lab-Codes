// WAP to construct a binary search tree from the given elements: 40, 20, 55, 12, 67, 4

#include<stdio.h>

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

int main()
{
    insert(40);
    insert(20);
    insert(55);
    insert(12);
    insert(67);
    insert(4);
    preorder(root);
    return 0;
}
