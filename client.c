#include<stdio.h>
#include<stdlib.h>
#include"linearalgebra.h"

int main()
{
    /*1. Programs for Vector Operations.*/
    Vector* v1, *v2, *v3;
    v1=malloc(sizeof(Vector));
    v2=malloc(sizeof(Vector));
    v3=malloc(sizeof(Vector));

    printf("Enter Vector 1:\n");
    Read_Vector(v1);
    printf("\nEnter Vector 2:\n");
    Read_Vector(v2);
    printf("\nEnter Vector 3:\n");
    Read_Vector(v3);

    printf("\nThe dot product of vectors 1 and 2 is %d\n", dotProduct(v1, v2));

    Vector* cross;
    cross=malloc(sizeof(Vector));
    crossProduct(v1, v2, cross);
    printf("The cross product of vectors 1 and 2 is <%d, %d, %d>\n", cross->i, cross->j, cross->k);

    printf("The scalar triple product of vectors 1, 2, and 3 is %d\n", scalarTripleProduct(v1, v2, v3));

    Vector* vtp;
    vtp=malloc(sizeof(Vector));
    vectorTripleProduct(v1, v2, v3, vtp);
    printf("The vector triple product of vectors 1, 2, and 3 is <%d, %d, %d>\n", vtp->i, vtp->j, vtp->k);

    free(v1); free(v2); free(v3);
    free(cross); free(vtp);
    printf("\nThis concludes the library display of available vector functions.\n\n\n*************\n\n\n");


    /*2. Programs for Operations on Complex Numbers.*/
    int sqr_size;
    printf("Enter size of complex square matrix: ");
    scanf("%d", &sqr_size);

    COMPLEX** a = malloc(sqr_size*sizeof(COMPLEX*));
    for (int i=0; i<sqr_size; i++)
        a[i] = malloc(sqr_size*sizeof(COMPLEX));

    printf("\n");
    Read_cmpMat(a, sqr_size);

    printf("\n");
    disp_cmpMat(a, sqr_size);

    printf("\nPrinting Transpose of Complex Matrix . . . \n\n");
    comp_transpose(a, sqr_size);
    disp_cmpMat(a, sqr_size);

    COMPLEX **hermit;
    hermit = malloc(sqr_size*sizeof(COMPLEX *));
    for (int i=0; i<sqr_size; i++)
    {
        hermit[i] = malloc(sqr_size*sizeof(COMPLEX));
    }

    comp_transpose(a, sqr_size);

    printf("\nIs a Hermitian?\t");
    if (ishermitian(a, sqr_size, hermit)) printf("Yes.\n\n");
    else printf("No.\n\n");
    printf("The transpose conjugate of the given matrix is:\n ");
    disp_cmpMat(hermit, sqr_size);

    free(a); free(hermit);
    printf("\nThis concludes the library display of available complex array functions.\n\n\n*************\n\n\n");


    /*3. Programs on Integer Arrays*/
    int sqr_size1;
    printf("Enter size of integer square matrix: ");
    scanf("%d", &sqr_size1);


    int **arr = malloc(sqr_size1 * sizeof(int*));

    for(int i = 0; i < sqr_size1 ; i++)
    {
        arr[i] = malloc(sqr_size1 * sizeof(int));
    }

    Read_intMat(arr, sqr_size1);
    printf("\n");
    disp_intMat(arr, sqr_size1);

    printf("\n\nTranspose of given matrix is: \n");
    transpose(arr, sqr_size1);
    disp_intMat(arr, sqr_size1);
    transpose(arr, sqr_size1);

    printf("\n\nDeterminant of the given matrix: %d\n", determinant(arr, sqr_size1));

    float **inv = malloc(sqr_size1 * sizeof(float*));

    for(int i = 0; i < sqr_size1 ; i++)
    {
        inv[i] = malloc(sqr_size1 * sizeof(float));
    }

    printf("\nThe inverse of the given matrix is: \n");
    matrix_inverse(arr, sqr_size1, inv);
    disp_floatMat(inv, sqr_size1);

    float **prod = malloc(sqr_size1 * sizeof(float*));

    for(int i = 0; i < sqr_size1 ; i++)
    {
        prod[i] = malloc(sqr_size1 * sizeof(float));
    }

    printf("\nMultiplying the matrix with its inverse, we get: \n");
    matrix_multiplication(arr, inv, prod, sqr_size1);
    disp_floatMat(prod, sqr_size1);

    free(arr); free(inv); free(prod);
    printf("\nThis concludes the library display of available integer array functions.\n\n\n*************\n\n\n");


    /*4. Simultaneous Equation Solver, by Cramer's Rule*/
    int n;
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

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

    printf("\nEnter the values for the resistance matrix:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("Enter value: ");
            scanf("%d", &res[i][j]);
        }
    }

    printf("\nEnter the values for the voltage matrix:\n");
    for (int i=0; i<n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &vol[i]);
    }

    cramer(res, vol, sol, n);
    printf("\nThe solutions are: \n");
    for (int i=0; i<n; i++)
    {
        printf("x%d = %.3f\n", i+1, sol[i]);
    }

    free(sol); free(res); free(vol);
    printf("\nThis concludes the library display of available simultaneous equation solver.\n\n\n*************\n\n\n");
    return 0;
}
