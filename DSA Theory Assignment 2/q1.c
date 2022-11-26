// Given a pre-order and an in-order traversal of a binary tree, design an applet that shows the step by step creation of the tree. Your program should also give a suitable response if no valid tree can be constructed from the input. Provide a set of test cases with your code.

#include <stdio.h>
#include <stdlib.h>
int c = 1;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int searching(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
struct node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    struct node *tNode = newNode(pre[preIndex++]);

    if (inStrt == inEnd)
        return tNode;


    printf("\nStep %d: \n", c);
    c++;
    printInorder(tNode);
    printf("\n");

    int inIndex = searching(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    printInorder(tNode);
    printf("\n");
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    printInorder(tNode);
    printf("\n");
    return tNode;
}

int main()
{
    int len;
    printf("Enter the size of tree: ");
    scanf("%d",&len);
    int in[len], pre[len];
    printf("Enter the inorder traversal: ");
    for(int i=0; i<len; i++){
        scanf("%d",&in[i]);
    }
    printf("Enter the preorder traversal: ");
    for(int i=0; i<len; i++){
        scanf("%d",&pre[i]);
    }
    struct node *root = buildTree(in, pre, 0, len - 1);
    printf("\nInorder traversal of the constructed tree is: ");
    printInorder(root);
    return 0;
}