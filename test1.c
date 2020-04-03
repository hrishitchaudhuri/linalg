//Program for dot product, cross product, scalar triple product, vector triple product, cartesian to polar
//User entered values for conversion from cartesian to polar and vice versa
//Hard coded values for other functions(change vectors a,b and c)


#include<stdio.h>
#include<math.h>
#define PI 3.141592
 
typedef struct
{
    float i,j,k;
}Vector;
//hard coded vector values (vectors a,b,c)
Vector a = {3,4,5},b = {0, 4, 0},c = {-1, 3, 3};
 
float dotProduct(Vector a, Vector b)
{
    return a.i*b.i+a.j*b.j+a.k*b.k;
}
 
Vector crossProduct(Vector a,Vector b)
{
    Vector c = {a.j*b.k - a.k*b.j, a.k*b.i - a.i*b.k, a.i*b.j - a.j*b.i};
    return c;
}
 
float scalarTripleProduct(Vector a,Vector b,Vector c)
{
    return dotProduct(a,crossProduct(b,c));
}
 
Vector vectorTripleProduct(Vector a,Vector b,Vector c)
{
    return crossProduct(a,crossProduct(b,c));
}
 
void printVector(Vector a)
{
    printf("( %f, %f, %f)",a.i,a.j,a.k);
}
 
int main()
{
    printf("\n a = ");
    printVector(a);
    printf("\n b = ");
    printVector(b);
    printf("\n c = ");
    printVector(c);
    printf("\n Dot Product = a . b = %f",dotProduct(a,b));
    printf("\n Cross Product = a x b = ");
    printVector(crossProduct(a,b));
    printf("\n Scalar Triple Product = a . (b x c) = %f",scalarTripleProduct(a,b,c));
    printf("\n Vector Triple Product = a x (b x c) = ");
    printVector(vectorTripleProduct(a,b,c));
    
    // Conversion from cartesian to polar
    float x, y, r, theta;
    printf("\nEnter cartesian coordinate x: ");
    scanf("%f", &x);
    printf("\nEnter cartesian coordinate y: ");
    scanf("%f", &y);
    /* Calculating r */
    r = sqrt(x*x + y*y);
       
    /* Calculating theta in radian */
    theta = atan(y/x);
       
    /* Converting theta from degree to radian */
    theta = 180.0 * theta/ PI;
       
    printf("\n Polar coordinate is: r = %0.2f and theta = %0.2f in degree\n", r, theta);
    
    // Conversion from polar to Cartesian
    float x2, y2, r2, theta2;
        
    printf("\n Enter radius of polar coordinate (r): ");
    scanf("%f", &r2);
    printf("\n Enter angle of polar coordinate in degree (theta): ");
    scanf("%f", &theta2);
       
    // Converting theta from degree to radian
    theta2 = theta2 * PI/180.0;
       
    // Calculating cartesian coordinate x
    x2 = r2 * cos(theta2);
       
    //Calculating cartesian coordinate y
    y2 = r2 * sin(theta2);
       
    printf("\n Cartesian coordinates are: (%0.3f, %0.3f)", x2, y2);

    return 0;
}
