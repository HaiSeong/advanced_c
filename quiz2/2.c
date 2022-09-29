
#include <stdio.h>

void sorting(int *S, int *E, int F);

int main()
{
	int array[10];
	int s, e, f;

	for (int *p = array; p < array + 10; p++)
		scanf("%d", p);

	while (1)
	{
		scanf("%d", &s);
		if (s == -1)
			break;
		scanf("%d", &e);
		scanf("%d", &f);
		sorting(array+s, array+e, f);
		for (int *p = array; p < array + 10; p++)
			printf("%d ", *p);
		printf("\n");
	}
	
}

void sorting(int *S, int *E, int F)
{
	int temp;

	if (F == 1)
	{
		for (int *p = S; p < E; p++)
		{
			for (int *p2 = S ; p2 < E; p2++)
			{
				if (*p2 < *(p2 + 1))
				{
					temp = *p2;
					*p2 = *(p2 + 1);
					*(p2 + 1) = temp;
				}
			}
		}
		return ;
	}
	
	for (int *p = S; p < E; p++)
	{
		for (int *p2 = S ; p2 < E; p2++)
		{
			if (*p2 > *(p2 + 1))
			{
				temp = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = temp;
			}
		}
	}
}