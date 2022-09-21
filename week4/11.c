
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[101], str2[101];
	int flag = 0;
	int len1, len2;
	int i, j;

	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (i=0; i<len1; i++)
	{
		for (j=0; j<len2; j++)
		{
			if (str1[i + j] != str2[j])
				break ;
		}
		if (j == len2)
		{
			flag = 1;
			break;
		}
	}

	printf("%d %d", strlen(str1), flag);
	
}