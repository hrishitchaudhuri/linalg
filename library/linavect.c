#include<stdio.h>
#include<stdlib.h>

    //Function to create and return a vector
Vector createvector(int i,int j,int k)
{
    Vector a={i,j,k};
    return a;
}

void Read_Vector(Vector* V)
{
    int i1, j1, k1;
    printf("Enter i-component of vector: ");
    scanf("%d", &i1);
    printf("Enter j-component of vector: ");
    scanf("%d", &j1);
    printf("Enter k-component of vector: ");
    scanf("%d", &k1);
    V->i=i1;
    V->j=j1;
    V->k=k1;
}


    //Function to find dot product of two vectors
int dotProduct(Vector* a, Vector* b)
{
    return (a->i)*(b->i)+(a->j)*(b->j)+(a->k)*(b->k);
}

    //Function to find cross product of two vectors
void crossProduct(Vector* a, Vector* b, Vector* c)
{
    c->i = a->j*b->k - a->k*b->j;
    c->j = a->k*b->i - a->i*b->k;
    c->k = a->i*b->j - a->j*b->i;
}

    //Function to find scalar triple product of 3 vectors
int scalarTripleProduct(Vector* a,Vector* b,Vector* c)
{
    Vector* temp = malloc(sizeof(Vector));
    crossProduct(b,c, temp);
    int stp = dotProduct(a,temp);
    free(temp);
    return stp;
}

    //Function to find vector triple product of 3 vectors
void vectorTripleProduct(Vector* a,Vector* b,Vector* c, Vector* d)
{
    Vector* temp = malloc(sizeof(Vector));
    crossProduct(b,c, temp);
    crossProduct(a,temp, d);
    free(temp);
}

    //Function to print a vector
void printVector(Vector a)
{
    printf("< %d, %d, %d>",a.i,a.j,a.k);
}
