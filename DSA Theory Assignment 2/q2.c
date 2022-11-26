#include <stdio.h>
#include <stdlib.h>

static int z = 1;

int curr[100];
int top = 0;

void add(int data)
{
    curr[top++] = data;
}

void delete ()
{
    top--;
}

int result[9];

//graph concepts starts here
int visited[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //this will come to use in DFS and BFS

int a[][9] =
    {{0, 4, 0, 0, 0, 0, 0, 8, 0},
     {4, 0, 8, 0, 0, 0, 0, 11, 0},
     {0, 8, 0, 7, 0, 4, 0, 0, 2},        //array ka indices tumhara vertices indicate kar rha hai.
     {0, 0, 7, 0, 9, 14, 0, 0, 0},       //jaha jaha v non zero hai wo edges hai
     {0, 0, 0, 9, 0, 10, 0, 0, 0},       //this matrix is called adjacency matrix
     {0, 0, 4, 14, 10, 0, 2, 0, 0},      //graph traversal -> DFS & BFS
     {0, 0, 0, 0, 0, 2, 0, 1, 6},        //graph operations
     {8, 11, 0, 0, 0, 0, 1, 0, 7},
     {0, 0, 2, 0, 0, 0, 6, 7, 0}};

//This function will find all SIMPLE PATHS from given source
void dfs(int s, int dis, int *ans, int final)
{
    if (s == final)
    {
        printf("\n");
        int sum = 0;
        printf("%d) ", z++);
        for (int i = 0; i < top; i++)
        {
            result[i] = curr[i];
            if (i < top)
                sum += a[curr[i]][curr[i + 1]];
        }
        for (int i = 0; i < top; i++)
        {
            printf("%d ", result[i]);
        }
        if (sum >= dis)
        {
            *ans = 1;
        }
        printf("dis = %d ", sum);
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (a[s][i] != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            add(i);
            dfs(i, dis, ans, final);
            visited[i] = 0;
            delete ();
        }
    }
}

int main()
{
    int ans = 0;
    int source;
    int target_len;
    printf("Enter target distance : ");
    scanf("%d", &target_len);
a:
    printf("\nEnter source : ");
    scanf("%d", &source);
    if (source >= 0 && source <= 8)
    {
        visited[source] = 1;
        add(source);
        for (int i = 0; i < 9; i++)
        {
            if(i != source)
            dfs(source, target_len, &ans, i);
        }
        if (ans == 1)
        {
            printf("\nTRUE");
        }
        else
        {
            printf("\nFALSE");
        }
    }
    else
    {
        printf("\n-----Please enter correct source b/w 0 and 8 (both included)!-----\n");
        goto a;
    }
    return 0;
}