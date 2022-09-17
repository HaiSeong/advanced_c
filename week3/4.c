
#include <stdio.h>

int main()
{
	char str1[101], str2[101];
	int i, length, flag = 1;

	scanf("%s", str1);
	scanf("%s", str2);
	i = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	length = i;
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			flag = 0;
			break ;
		}
		i++;
	}
	printf("%d %d\n", length, flag);
}
