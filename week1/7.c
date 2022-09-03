
#include <stdio.h>

void input(int *px, int *py, int *pz);
void output(int *px, int *py, int *pz);

 
int main()
{
	int x, y, z;

	input(&x, &y, &z);
	output(&x, &y, &z);
}

void input(int *px, int *py, int *pz)
{
	scanf("%d%d%d", px, py, pz);
}

void output(int *px, int *py, int *pz)
{
	printf("%d %d %d\n", *px, *py, *pz);
}