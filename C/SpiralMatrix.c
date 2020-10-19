#include <stdio.h>
#include <stdlib.h>


int* getSpiralMatrix(int** mat, int n)
{
    int* spiralMat = (int*)malloc((n * n) * sizeof(int));

    // If matrix is empty
    if (n == 0)
        return spiralMat;
    
    int r1 = 0;
    int r2 = n - 1;
    int c1 = 0;
    int c2 = n - 1;
    int p = 0;
    while (r1 <= r2 && c1 <= c2)
    {
        for (int c = c1; c <= c2; c++)
        {
            spiralMat[p++] = mat[r1][c];
        }

        for (int r = r1 + 1; r <= r2; r++)
        {
            spiralMat[p++] = mat[r][c2];
        }

        if (r1 < r2 && c1 < c2)
        {
            for (int c = c2 - 1; c > c1; c--)
            {
                spiralMat[p++] = mat[r2][c];
            }

            for (int r = r2; r > r1; r--)
            {
                spiralMat[p++] = mat[r][c1];
            }
        }

        r1++;
        c1++;
        r2--;
        c2--;
    }

    return spiralMat;
}


int main()
{
    int n;
    scanf("%d", &n);
    int** mat = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int*)malloc(n * sizeof(int));
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            scanf("%d", &mat[r][c]);
        }
    }

    int* spiralMat = getSpiralMatrix(mat, n);
    for (int i = 0; i < (n * n); i++)
    {
        printf("%d ", spiralMat[i]);
    }
}
