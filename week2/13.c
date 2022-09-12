
#include <stdio.h>

int arrsum(int *start, int *end);

int main()
{
	int N, S, E;
	int array[100];
	int *p;

	scanf("%d%d%d", &N, &S, &E);
	for (p = array; p < array + N; p++)
	{
		scanf("%d", p);
	}

	printf("%d\n", arrsum(array + S, array + E));
}

int arrsum(int *start, int *end)
{
	int *temp;
	int sum;

	sum = 0;
	for (temp = start; temp <= end; temp++)
	{
		sum += *temp;
	}
	return sum;
}
