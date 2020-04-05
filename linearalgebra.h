//Program for dot product, cross product, scalar triple product, vector triple product, cartesian to polar
//User entered values for conversion from cartesian to polar and vice versa

int sqr_size = 3;

//Vector data type structure
typedef struct
{
    float i,j,k;
}Vector;

float dotProduct(Vector a, Vector b);

Vector crossProduct(Vector a,Vector b);

float scalarTripleProduct(Vector a,Vector b,Vector c);

Vector vectorTripleProduct(Vector a,Vector b,Vector c);

void printVector(Vector a);

Vector createover(float i,float j,float k);

//Complex numbers,matrices and determinants
typedef struct complex_no
{
    int re;
    int im;
} COMPLEX ;

COMPLEX cmp(int a, int b);

COMPLEX conjugate(struct complex_no a);

void comp_transpose (COMPLEX ** a, int n);

int ishermitian(COMPLEX **a, int n);

void transpose (float **a, int n);

void cofactor (int **a, int **b, int i, int j, int n);

int determinant (int **a, int n);

void matrix_inverse (int **a, int n, float **cof_matrix2);

void matrix_multiplication(int **mult1, float **mult2, float **prod, int n);

//Simultaneous equation
float *cramer(int **res, int *vol, int n);









