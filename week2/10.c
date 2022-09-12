
#include <stdio.h>

void swap(int *pa, int *pb);
void gcdlcm(int a, int b, int *gcd, int *lcm);

int main()
{
	int a, b;
	int gcd, lcm;

	scanf("%d%d", &a, &b);
	
	gcdlcm(a, b, &gcd, &lcm);
	printf("%d %d\n", gcd, lcm);
}

void swap(int *pa, int *pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void gcdlcm(int a, int b, int *gcd, int *lcm)
{
	int i;
	
	*gcd = 1;

	if (a > b)
		swap(&a, &b);
	
	for (i=2; i<=a; i++)
	{
		if (a % i == 0 && b % i == 0)
			*gcd = i;
	}
	*lcm = a * b / *gcd;
}
