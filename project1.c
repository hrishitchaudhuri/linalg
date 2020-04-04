#include<stdio.h>
#include<stdlib.h>

typedef struct complex_no{
    int re;
    int im;
} COMPLEX;
/*
COMPLEX cmp(int a, int b){
    COMPLEX x = {a, b};
    return x;
}
*/
COMPLEX conjugate(struct complex_no a)
{
    struct complex_no a_con;
    a_con.re=a.re;
    a_con.im=a.im;
    return a_con;
}

void comp_transpose (COMPLEX ** a, int n)
{
    COMPLEX temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = *(*(a + i) + j);
            *(*(a + i) + j) = *(*(a + j) + i);
            *(*(a + j) + i) = temp;
        }
    }
  //return a;
}

int ishermitian(COMPLEX **a, int n)
{
    COMPLEX **hermit;
    hermit = malloc(n*sizeof(COMPLEX *));

    for (int i=0; i<n; i++)
    {
        hermit[i] = malloc(n*sizeof(COMPLEX));
    }

    for (int i=0; i<n; i++)
    {
            for (int j=0; j<n; j++)
        {
            *(*(hermit+i)+j)=*(*(a+i)+j);
        }
    }

    comp_transpose(hermit, n);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            *(*(hermit+i)+j)=conjugate(*(*(hermit+i)+j));
        }
    }

    if (hermit==a)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int sqr_size = 3;
void transpose (int **a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = *(*(a + i) + j);
            *(*(a + i) + j) = *(*(a + j) + i);
            *(*(a + j) + i) = temp;
        }
    }
}

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

void matrix_inverse (int **a, int n, float **cof_matrix2)
{
    int d = determinant (a, sqr_size);
    int det_sign = 1;
    int res = 0;
    int **cof_matrix1;
    cof_matrix1 = malloc ((n - 1) * sizeof (int *));

    for (int i = 0; i < (n - 1); i++)
    {
        cof_matrix1[i] = malloc ((n - 1) * sizeof (int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cofactor (a, cof_matrix1, i, j, n);
            res = det_sign * determinant (cof_matrix1, sqr_size-1);
            cof_matrix2[i][j] = (float) res;
            det_sign = 0 - det_sign;
        }
    }
  /*for(int j = 0 ; j < sqr_size ; j++){
     cofactor(a, cof_matrix, 0, j, sqr_size);
     res+=(det_sign*(*(*(a+0)+j))*determinant(cof_matrix, sqr_size-1));
     det_sign = 0-det_sign;
     }*/
  /*
     printf("Cof matrix: \n");
     for (int i=0; i<sqr_size; i++)
     {
     for (int j=0; j<sqr_size; j++)
     {
     printf("%d + %di\t", cof_matrix[i][j], cof_matrix[i][j]);
     }
     printf("\n");
     } */
    transpose (cof_matrix2, sqr_size);

    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            cof_matrix2[i][j] = (float) cof_matrix2[i][j]/(float) d;
        }
    }
}

void matrix_multiplication(int **mult1, float **mult2, float **prod, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prod[i][j]=0;
            for (int k = 0; k < n; k++)
            {
                prod[i][j]+=(mult1[i][k]*mult2[k][j]);
            }
        }
    }
}

int main ()
{
  //printf("Start ok");
    COMPLEX **arr = malloc(sqr_size * sizeof(COMPLEX*));

    for(int i = 0; i < sqr_size ; i++)
    {
        arr[i] = malloc(sqr_size * sizeof(COMPLEX));
    }

    for(int i = 0 ; i < sqr_size ; i++)
    {
        for(int j = 0 ; j < sqr_size ; j++)
        {
            arr[i][j].re = i;
            arr[i][j].im = j;
        }
    }

    for (int i=0; i<sqr_size; i++)
    {
        for (int j=0; j<sqr_size; j++)
        {
            printf("%d + %di\t", arr[i][j].re, arr[i][j].im);
        }
        printf("\n");
    }

    printf("\n");

    comp_transpose(arr, sqr_size);
    for (int i=0; i<sqr_size; i++)
    {
        for (int j=0; j<sqr_size; j++)
        {
            printf("%d + %di\t", arr[i][j].re, arr[i][j].im);
        }
        printf("\n");
    }

    if (ishermitian(arr, sqr_size)) printf("Matrix is hermitian\n");
    else printf("Matrix is not hermitian\n\n");

    free(arr);


    int **a;
    int inc = 1;

    a = (int **) malloc (sqr_size * sizeof (int *));

    for (int i = 0; i < sqr_size; i++)
    {
        a[i] = (int *) malloc (sqr_size * sizeof (int));
    }

    int start = 1;

    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            a[i][j] = start;
            start += inc;
            inc += 4;
        }
    }

    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            printf ("%d ", a[i][j]);
        }
        printf ("\n");
    }

    transpose (a, sqr_size);
    printf ("\n");

    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            printf ("%d ", a[i][j]);
        }
        printf ("\n");
    }

    printf ("\n");
    int D;
    D = determinant (a, sqr_size);
    printf ("%d\n\n", D);

    float **inverse;
    inverse = malloc (sqr_size * sizeof (float *));
    int n = sqr_size;
    for (int i = 0; i < n; i++)
    {
        inverse[i] = malloc (n * sizeof (float));
    }

    matrix_inverse (a, n, inverse);
    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            printf ("%.4f ", inverse[i][j]);
        }
        printf ("\n");
    }

    float **final_mat;
    final_mat = malloc (sqr_size * sizeof (float *));
    for (int i = 0; i < n; i++)
    {
        final_mat[i] = malloc (n * sizeof (float));
    }

    matrix_multiplication(a, inverse, final_mat, n);

    printf("\n");
    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            printf ("%.2f ", final_mat[i][j]);
        }
        printf ("\n");
    }

    free (a);

    return 0;
}
