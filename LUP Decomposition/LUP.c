#include<stdio.h>
#include<stdlib.h>

// ! REMOVE STRUCTS. USE POINTERS.
/*
typedef struct vector {
    float size;
    float *elem;
} VECT;

typedef struct matrix {
    float row; float col;
    float** elems;
} MAT;

typedef struct perm_matrix {
    float size;
    float* pi_els;
} PMAT;
*/

/*
 * The idea behind LUP decomposition is as follows:
 *          Given a system of linear equations Ax = b in n unknowns where A is a n x n matrix, 
 *          b is an n-row vector and x is the desired solution vector. 
 * 
 * Therefore, we intend to find three n x n matrices L, U, and P such that PA = LU
 * where L is a lower triangular matrix, U is an upper triangular matrix, and P is 
 * a permutation matrix. 
 * 
 * Once we find L, U, and P, we can rewrite 
 *          Ax = b      ==>     PAx = Pb
 *          PAx = Pb    ==>     LUx = Pb
 *  Let y = Ux
 *          LUx = Pb    ==>     Ly = Pb
 * 
 * We will solve for y using forward substitution. We then solve the upper triangular
 * system, Ux = y, for the unknown vector x using back substitution. 
 */


// Forward Substitution
double* for_sub(int* P, double* b, double** L, int n) {
    double* y;
    y=(double*)malloc(sizeof(double)*n);

    double cnt=0;
    for (register int i=0; i<n; i++) {
        for (register int j=0; j<i; j++)
            cnt+=(L[i][j]*y[j]);
        y[i]=b[P[i]]-cnt;
        cnt=0;
    }

    printf("\n\n");

    return y;
}


// Back Substitution
double* bac_sub(double** U, double* y, int n) {
    double* x;
    x=(double*)malloc(sizeof(double)*n);

    double cnt=0;
    for (register int i=n-1; i>=0; i--) {
        for (register int j=i+1; j<n; j++) {
            cnt+=(double)(((float)U[i][j]) * ((float)x[j]));
            printf(" U[I][J]: %lf  x[J]: %lf ", U[i][j], x[j]);
            printf("cnt: %lf ", cnt);
        }
        x[i] = (double) (y[i]-cnt)/U[i][i];
        cnt=0;
    }

    return x;
}


// Solving for x
double* lup_sol(double** L, double** U, int* P, double* B, int n) {
    double* y=for_sub(P, B, L, n);
    double* x=bac_sub(U, y, n);

    for (register int i=0; i<n; i++)
        printf("%lf ", y[i]);
    printf("\n\n");
    free(y);
    return x;
}

int main() {
    int n=3;
    double r;
    double** L=(double**)malloc(sizeof(double*)*n);
    for (register int i=0; i<n; i++) {
        L[i]=(double*)malloc(sizeof(double)*n);
        for (register int j=0; j<n; j++) {
            scanf("%lf", &r);
            L[i][j]=r;
        }
    }

    
    double** U=(double**)malloc(sizeof(double*)*n);
    for (register int i=0; i<n; i++) {
        U[i]=(double*)malloc(sizeof(double)*n);
        for (register int j=0; j<n; j++) {
            scanf("%lf", &r);
            U[i][j]=r;
        }
    }

    for (register int i=0; i<n; i++) {
        for (register int j=0; j<n; j++) {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }
    printf("\n");
        
    int* P=(int*)malloc(sizeof(int)*n);
    for (register int i=0; i<n; i++) {
        scanf("%lf", &r);
        P[i]=r;
    }
    
    double* b=(double*)malloc(sizeof(double)*n);
    for (register int i=0; i<n; i++) {
        scanf("%lf", &r);
        b[i]=r;
    }

    double* x=lup_sol(L, U, P, b, n);
    for (register int i=0; i<n; i++)
        printf("%lf ", x[i]);
    
    printf("\n");
    return 0;
}