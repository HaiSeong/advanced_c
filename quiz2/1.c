
#include <stdio.h>

int count(char *str1, char *str2, int len1, int len2);

int main()
{
	char str1[20], str2[20];
	int len1, len2;

	scanf("%d%d", &len1, &len2);

	scanf("%s", str1);
	scanf("%s", str2);
		
	printf("%d\n",count(str1, str2, len1, len2));
}

int count(char *str1, char *str2, int len1, int len2)
{
	char *p1 = str1;
	char *p2 = str2;
	int flag;
	int cnt = 0;

	for (char *p1 = str1; p1 < str1 + len1; p1++)
	{
		flag = 1;
		char *p = p1;
		for (char *p2 = str2; p2 < str2 + len2; p2++)
		{
			if (*p != *p2)
			{
				flag = 0;
				break;
			}
			p++;
		}
		if (flag == 1)
			cnt++;
	}

	return cnt;
}