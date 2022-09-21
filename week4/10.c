
#include <stdio.h>
#include <string.h>

int main()
{
	char str[101], minStr[101];
	int len, n, i, flag = 1, min = 101;

	scanf("%d", &n);
	getchar();
	
	for (i = 0; i < n; i++)
	{
		gets(str);
		if (min > strlen(str))
		{
			min = strlen(str);
			strcpy(minStr, str);
		}
		fflush(stdin);
	}
	printf("%s\n", minStr);
}