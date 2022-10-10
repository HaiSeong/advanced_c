
#include <stdio.h>

typedef struct complex
{
    double real;
    double imaginary;
} Complex;

Complex add(Complex c1, Complex c2);

int main()
{
    Complex c1, c2, c;

    scanf("%lf%lf", &(c1.real), &(c1.imaginary));
    scanf("%lf%lf", &(c2.real), &(c2.imaginary));

    c = add(c1, c2);

    printf("%.1lf + %.1lfi\n", c.real , c.imaginary);
}

Complex add(Complex c1, Complex c2)
{
    Complex c;

    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;

    return c;
}