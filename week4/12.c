
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[101], str2[101];
	int cnt = 0;
	int len1, len2;
	int i, j;

	gets(str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	i = 0;
	while (i < len1)
	{
		if (str1[i] == str2[0])
		{
			for (j = 1; j < len2 && i + j < len1; j++)
			{
				if (str1[i + j] != str2[j])
					break ;
			}
			if (j == len2)
			{
				cnt++;
				i += len2;
			}
			else
				i++;
		}
		else
			i++;
	}
	

	printf("%d", cnt);
	
}