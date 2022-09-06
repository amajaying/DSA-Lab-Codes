#include <stdio.h>

int main()
{
    int row, column, tripletr1 = 0, tripletr2 = 0;
    printf("Enter rows and columns of sparse matrix: ");
    scanf("%d %d", &row, &column);
    int sparse1[row][column];
    int sparse2[row][column];
    printf("\nEnter elements of sparse matrix 1:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter element %dx%d: ", i + 1, j + 1);
            scanf("%d", &sparse1[i][j]);
            if (sparse1[i][j] != 0)
            {
                tripletr1++;
            }
        }
    }
    printf("\nEnter elements of sparse matrix 2:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter element %dx%d: ", i + 1, j + 1);
            scanf("%d", &sparse2[i][j]);
            if (sparse1[i][j] != 0)
            {
                tripletr2++;
            }
        }
    }
    printf("\nFirst matrix entered was:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", sparse1[i][j]);
        }
        printf("\n");
    }
    printf("\nSecond matrix entered was:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", sparse2[i][j]);
        }
        printf("\n");
    }
    int triplet1[tripletr1 + 1][3];
    triplet1[0][0] = row;
    triplet1[0][1] = column;
    triplet1[0][2] = tripletr1;
    int count1 = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sparse1[i][j] != 0)
            {
                triplet1[count1][0] = i;
                triplet1[count1][1] = j;
                triplet1[count1][2] = sparse1[i][j];
                count1++;
            }
        }
    }
    printf("\nThe triplet of the first matrix is:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= tripletr1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", triplet1[i][j]);
        }
        printf("\n");
    }
    int triplet2[tripletr2 + 1][3];
    triplet2[0][0] = row;
    triplet2[0][1] = column;
    triplet2[0][2] = tripletr2;
    int count2 = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sparse2[i][j] != 0)
            {
                triplet2[count2][0] = i;
                triplet2[count2][1] = j;
                triplet2[count2][2] = sparse2[i][j];
                count2++;
            }
        }
    }
    
    int trip_trans1[3][tripletr1 + 1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= tripletr1; j++)
        {
            trip_trans1[i][j] = triplet1[j][i];
        }
    }
    printf("\nThe transpose of first triplet is:\n");
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("Row\t");
        }
        if (i == 1)
        {
            printf("Column\t");
        }
        if (i == 2)
        {
            printf("Value\t");
        }
        for (int j = 0; j <= tripletr1; j++)
        {
            printf("%d\t", trip_trans1[i][j]);
        }
        printf("\n");
    }
    
    int sum[tripletr1][3];
    if (tripletr1 == tripletr2)
    {
        for (int i = 0; i <= tripletr1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum[i][j] = triplet1[i][j] + triplet2[i][j];
            }
        }
        printf("\nSum of both the matrix is:\n");
        for (int i = 0; i <= tripletr1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d\t", sum[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The size of triplets don't match so summation does not exist");
    }

    return 0;
}