#include<stdio.h>
#include<stdlib.h>
#include"linearalgebra.h"

//1)Program for dot product, cross product, scalar triple product, vector triple product, cartesian to polar
//User entered values for conversion from cartesian to polar and vice versa

//Function to create and return a vector
Vector createvector(float i,float j,float k)
{
    Vector a={i,j,k};
    return a;
}

//Function to find dot product of two vectors
float dotProduct(Vector a, Vector b)
{
    return a.i*b.i+a.j*b.j+a.k*b.k;
}

//Function to find cross product of two vectors
Vector crossProduct(Vector a,Vector b)
{
    Vector c = {a.j*b.k - a.k*b.j, a.k*b.i - a.i*b.k, a.i*b.j - a.j*b.i};
    return c;
}

//Function to find scalar triple product of 3 vectors
float scalarTripleProduct(Vector a,Vector b,Vector c)
{
    return dotProduct(a,crossProduct(b,c));
}

//Function to find vector triple product of 3 vectors
Vector vectorTripleProduct(Vector a,Vector b,Vector c)
{
    return crossProduct(a,crossProduct(b,c));
}

//Function to print a vector
void printVector(Vector a)
{
    printf("( %f, %f, %f)",a.i,a.j,a.k);
}

//2)Complex numbers,matrices and determinants

//Function for finding conjugate of a complex number
COMPLEX conjugate(struct complex_no a)
{
    struct complex_no a_con;
    a_con.re=a.re;
    a_con.im=0-a.im;
    return a_con;
}

//Function for transposing a complex matrix
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
}

//Function for checking if a complex matrix is hermitian or not
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

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (a[i][j].re!=hermit[i][j].re && a[i][j].im != hermit[i][j].im) {return 0;}
        }
    }

    return 1;
}

//Function for transposing integer 2D matrix
void transpose (float **a, int n)
{
    float temp;
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


//Function for finding cofactor of an array,**a is source matrix,**b is source pointer
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

//Function for finding determinant of an array
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

//Array matrix to which the inverse is assigned
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
    transpose (cof_matrix2, sqr_size);

    for (int i = 0; i < sqr_size; i++)
    {
        for (int j = 0; j < sqr_size; j++)
        {
            cof_matrix2[i][j] = (float) cof_matrix2[i][j]/(float) d;
        }
    }
}

//Function for matrix multiplication,first two arguments are the arrays to be multiplied,third argument is the product
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


//3)Simultaneous equations
//Function for solving a system of linear equations by cramers rule
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
