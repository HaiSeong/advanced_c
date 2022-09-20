
#include <stdio.h>


int *sel_increase(int *x, int *end);

int main()
{
	int *temp;
	int x[20];
	int *px, i=0, len = 0;

	for (px = x; px < x + 20; px++)
	{
		scanf("%d", px);
		if (*px == -1)
			break;
		len++;
	}
	if (len < 1)
		return 0;

	px = sel_increase(x, x + len);

	while (*px < *(px + 1))
	{
		printf("%d ", *px);
		px++;
	}
	printf("%d ", *px);
	
}

int *sel_increase(int *x, int *end)
{
	int *px, *maxp = x;
	int cnt = 1, max = 0;

	for (px = x; px+1 < end; px++)
	{
		if (*px < *(px + 1))
		{
			cnt ++;
			if (max <= cnt)
			{
				max = cnt;
				maxp = px - cnt + 2;
			}
		}
		else
		{
			cnt = 1;
			if (max <= cnt)
			{
				max = cnt;
				maxp = px - cnt + 2;
			}
		}
	}

	return maxp;
}