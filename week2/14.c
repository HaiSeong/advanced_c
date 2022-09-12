
#include <stdio.h>

int add_to_k(int *start, int *end);

int main()
{
	int d[100];
	int *pd, *pd2;
	int N, sum;

	scanf("%d", &N);
	for (pd = d; pd < d + N; pd++)
		scanf("%d", pd);

	sum = 0;
	for (pd = d; pd < d + N; pd++)
		sum += add_to_k(d, pd);

	printf("%d\n", sum);
}

int add_to_k(int *start, int *end)
{
	int *temp;
	int sum = 0;

	for (temp = start; temp <= end; temp++)
		sum += *temp;

	return sum;
}