
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[101], str2[101];

	scanf("%s", str1);
	scanf("%s", str2);

	if (strcmp(str1, str2) > 0)
	{
		strcat(str1, str2);
		printf("%s\n", str1);
	}
	else
	{
		strcat(str2, str1);
		printf("%s\n", str2);
	}

	
}