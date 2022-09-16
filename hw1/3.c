
#include <stdio.h>

void PRT(int n, char *p);

int main()
{
	char str[100];
	char *p, *pmax;
	int cnt = 0, max = 0;

	p = str;
	while (1)
	{
		scanf("%c", p);
		if (*p == '#')
			break;
		p++;
	}

	p = str;
	while (1)
	{
		if (*p == '#')
		{
			printf("\n");
			break;
		}
		if ('a' <= *p && *p <= 'z')
		{
			printf("%c", *p);
			cnt++;
			p++;
		}
		else
		{
			if (max < cnt)
			{
				max = cnt;
				pmax = p - cnt;
			}
			cnt = 0;
			while (!('a' <= *p && *p <= 'z'))
			{
				if (*p == '#')
				{
					break;
				}
				p++;
			}
			if ('a' <= *(p + 1) && *(p + 1) <= 'z')
				printf("\n");
		}
	}

	printf("%d %c\n", max, *pmax);
	PRT(max, pmax);
}

void PRT(int n, char *p)
{
	char *temp;

	for (temp = p; temp < p + n; temp++)
	{
		printf("%c", *temp);
	}
	printf("\n");
}
