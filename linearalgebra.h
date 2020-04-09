typedef struct vect1
{
    int i;
    int j;
    int k;
}Vector;

typedef struct complex_no
{
    int re;
    int im;
} COMPLEX ;

void Read_Vector(Vector*);

Vector createvector(int, int, int);

int dotProduct(Vector*, Vector *);

void crossProduct(Vector* ,Vector*, Vector*);

int scalarTripleProduct(Vector* ,Vector* ,Vector*);

void vectorTripleProduct(Vector* ,Vector* ,Vector *, Vector*);

void printVector(Vector a);

void Read_cmpMat(COMPLEX**, int);

void disp_cmpMat(COMPLEX**, int);

COMPLEX cmp(int a, int b);

COMPLEX conjugate(struct complex_no a);

void comp_transpose (COMPLEX ** a, int n);

int ishermitian(COMPLEX**, int, COMPLEX**);

void Read_intMat(int**, int);

void disp_intMat(int**, int);

void disp_floatMat(float** , int);

void transpose (float **a, int n);

void cofactor (int **a, int **b, int i, int j, int n);

int determinant (int **a, int n);

void matrix_inverse (int **a, int n, float **cof_matrix2);

void matrix_multiplication(int **mult1, float **mult2, float **prod, int n);

void cramer(int **res, int *vol, float *sol, int n);
