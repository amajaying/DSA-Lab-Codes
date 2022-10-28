// WAP to implement N-ary (n-degree) tree using array having the following operations:
// Insert a Node
// Traverse

#include<stdio.h>
#include<stdlib.h>

int arr[100];

void traverse(int root, int degree)
{
    if(root == -1)
    {
        return;
    }
    printf("%d ", arr[root]);
    for(int i = 1; i <= degree; i++)
    {
        traverse(root * degree + i, degree);
    }
}


void insert(int data)
{
    int i;
    for(i = 0; i < 100; i++)
    {
        if(arr[i] == 0)
        {
            arr[i] = data;
            break;
        }
    }
}

int main(){
    int n, degree;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the degree of the tree: ");
    scanf("%d", &degree);

    int i, data;
    for(i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    traverse(0, degree);
    return 0;
    
}