
#include <stdio.h>

void swap(int *pa, int *pb);
int *mid(int array[]);

int main()
{
	int array[3];
	int *p;

	for (p=array; p < array + 3; p++)
		scanf("%d", p);
	
	p = mid(array);
	printf("%d\n", *p);
}

void swap(int *pa, int *pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int *mid(int array[])
{
	int *p;

	p = array;
	if (*p > *(p + 1))
		swap(p, p+1);
	if (*(p + 1) > *(p + 2))
		swap(p+1, p+2);
	if (*p > *(p + 1))
		swap(p, p+1);

	return (p+1);	
}