
#include <stdio.h>

void swap(int *pa, int *pb);
 
int main()
{
	int n;
	int array[50];
	int a, b, i;

	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &array[i]);
	scanf("%d%d", &a, &b);
	
	swap(&array[a], &array[b]);

	for (i=0; i<n; i++)
		printf(" %d", array[i]);
}

void swap(int *pa, int *pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
