
#include <stdio.h>

void addArray(int *a, int *b, int *c, int n);

int main()
{
	int n;
	int *p;
	int a[20], b[20], c[20];

	scanf("%d", &n);
	for (p=a; p < a + n; p++)
		scanf("%d", p);
	for (p=b; p < b + n; p++)
		scanf("%d", p);

	addArray(a, b, c, n);
	
	for (p=c; p < c + n; p++)
		printf(" %d", *p);
}

void addArray(int *a, int *b, int *c, int n)
{
	int *pa, *pb, *pc;
	int i;

	pa = a;
	pb = b + n - 1;
	pc = c;
	for (i = 0; i < n; i++)
	{
		*(pc) = *(pa) + *(pb);
		pa++;
		pb--;
		pc++;
	}
}
