// 3 WAP to  traverse binary search tree;
// 	1 Inorder Traversal
// 	2. Preorder Traversal
// 	3. Post Order Traversal


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

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    int n,i,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        insert(data);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("Preorder Traversal: ");
    preorder(root);
    printf("Postorder Traversal: ");
    postorder(root);
    return 0;
}