#include<stdio.h>
#include<stdlib.h>
void cofactor (int **a, int **b, int i, int j, int n)
{
    int row = 0, col = 0;
    for (int loop_1 = 0; loop_1 < n; loop_1++)
    {
        for (int loop_2 = 0; loop_2 < n; loop_2++)
        {
            if (loop_1 != i && loop_2 != j)
            {
                *(*(b + row) + col) = *(*(a + loop_1) + loop_2);
                col++;
                if (col == (n - 1))
                {
                    col = 0;
                    row++;
                }
            }
        }
    }
}

int determinant (int **a, int n)
{
    int res = 0;
    int det_sign = 1;
    int **cof_matrix;

    if (n == 1)
    {
        return *(*(a + 0) + 0);
    }

    cof_matrix = (int **) malloc ((n - 1) * sizeof (int *));

    for (int i = 0; i < (n - 1); i++)
    {
        cof_matrix[i] = (int *) malloc ((n - 1) * sizeof (int));
    }

    for (int j = 0; j < n; j++)
    {
        cofactor (a, cof_matrix, 0, j, n);
        res += (det_sign * (*(*(a + 0) + j)) * determinant (cof_matrix, n - 1));
        det_sign = 0 - det_sign;
    }
    return res;
}

float *cramer(int **res, int *vol, int n)
{
    int det=determinant(res, n);
    float *sol;
    sol=malloc(n*sizeof(float));

    int **x;
    x=malloc(n*sizeof(int *));
    for (int i=0; i<n; i++)
    {
        x[i]=malloc(n*sizeof(int));
    }

    if (det==0)
    {
        printf("Infinite solutions");
        exit(0);
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            x[i][j]=res[i][j];
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            x[j][i]=vol[j];
        }
        sol[i]= (float) determinant(x, n)/((float) det);
        for (int j=0; j<n; j++)
        {
            x[j][i]=res[j][i];
        }
    }

    return sol;
}

int main()
{
    int n=3;

    int **res;
    res=malloc(n*sizeof(int *));
    for (int i=0; i<n; i++)
    {
        res[i]=malloc(n*sizeof(int));
    }

    float *sol;
    sol=malloc(n*sizeof(float));

    int *vol;
    vol=malloc(n*sizeof(int));

    int res1[3][3] = {{7, -4, 0},{4, -15, 6}, {0, -6, 13}};
    int vol1[3] = {67, 152, 74};

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            res[i][j]=res1[i][j];
        }
        vol[i]=vol1[i];
    }
    sol = cramer(res, vol, n);

    for (int i=0; i<n; i++)
        printf("%.2f\t", sol[i]);

    return 0;
}
