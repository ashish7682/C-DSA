#include <stdio.h>

int main()
{
    int a[3][3], k = 0, c = 0;
    printf("Enter matrix element: ");
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != 0)
            {
                c++;
            }
        }
    }

    int b[3][c];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != 0)
            {
                b[0][k] = i;
                b[1][k] = j;
                b[2][k] = a[i][j];
                k++;
            }
        }
    }
    printf("Matrix representation:\n ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}