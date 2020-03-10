#include<stdio.h>

typedef struct vector{
	int i, j, k;
}VECT;

VECT vect(int i , int j , int k){
	VECT v = {i,j,k};
	return v;
}

VECT v_add(VECT a, VECT b){
	VECT v = {a.i + b.i , a.j+b.j, a.k+b.k};
	return v;
}

double v_dot(VECT a, VECT b){
	double v = (double)a.i*b.i + a.j*b.j + a.k*b.k;
	return v;
}

VECT v_cross(VECT a, VECT b);

void showvect(VECT a){
	printf("<%d, %d, %d>\n", a.i, a.j, a.k);
}

int main()
{
	printf("%lf", v_dot(vect(5,6,7), vect(1,2,3)));
	return 0;
}