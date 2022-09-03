
#include <stdio.h>

int main()
{
	char ch[10];
	char *p;
	char *p2;
	int cnt;
	int max = 0;
	char *max_p = ch;

	for (p = ch; p < ch+10; p++)
	{
		scanf("%c", p);
	}
	for (p = ch; p < ch+10; p++)
	{
		cnt = 0;
		for (p2 = ch; p2 < ch+10; p2++)
		{
			if (*p == *p2)
				cnt++;
		}
		if (max < cnt)
		{
			max = cnt;
			max_p = p;
		}
	}

	printf("%c %d\n", *max_p, max);
}