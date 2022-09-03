
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *p;
	int *array;
	int cnt;

	scanf("%d", &n);
	array = (int *)malloc(sizeof(int) * n);

	p = array;
	while (p < array + n)
	{
		scanf("%d", p);
		p++;
	}
	
	p = array;
	cnt = 0;
	while (p < array + n)
	{
		if (*p == 0)
		{
			printf("%d\n", cnt);
			break;
		}
		p++;
		cnt++;
	}
}