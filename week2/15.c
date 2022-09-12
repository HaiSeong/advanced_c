
#include <stdio.h>

void swap(int *pa, int *pb);
void ABC(int *start, int k);

int main()
{
	int array[10];
	int *p;
	int n = 10;

	for (p = array; p < array + 10; p++)
		scanf("%d", p);

	for (p = array; p < array + 10; p++)
	{
		ABC(p, n);
		n--;
	}
	
	for (p = array; p < array + 10; p++)
		printf(" %d", *p);
}

void swap(int *pa, int *pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void ABC(int *start, int k)
{
	int *temp;
	int max = *start;
	int *pmax = start;

	for (temp = start + 1; temp < start + k; temp++)
	{
		if (max < *temp)
		{
			max = *temp;
			pmax = temp;
		}
	}
	swap(pmax, start);
}