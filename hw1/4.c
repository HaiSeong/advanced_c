
#include <stdio.h>

void swap(int *pa, int *pb);
void ABC(int *start, int k);

int main()
{

	int room1[10], room2[10], all[20];
	int n = 0, m = 0, cnt;
	int *temp;

	temp = room1;
	while (1)
	{
		scanf("%d", temp);
		if (*temp == -1)
			break;
		*(all + n) = *temp;
		n++;	
		temp++;
	}

	temp = room2;
	while (1)
	{
		scanf("%d", temp);
		if (*temp == -1)
			break;
		*(all + n + m) = *temp;
		m++;	
		temp++;
	}
	
	cnt = n + m;
	for (temp = all; temp < all + n + m; temp++)
	{
		ABC(temp, cnt);
		cnt--;
	}

	for (temp = all; temp < all + n; temp++)
		printf("%d ", *temp);
	printf("\n");
	for (temp = all + m + n - 1; temp >= all + n; temp--)
		printf("%d ", *temp);
	printf("\n");
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