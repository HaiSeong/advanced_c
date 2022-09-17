
#include <stdio.h>

int main()
{
	char str[101], copy[101];
	int i, j, length, index;

	scanf("%s", str);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	length = i;
	copy[length] = '\0';
	for (i = 0; i < length; i++)
	{
		index = 0;
		for (j = i; j < length; j++)
			copy[index++] = str[j];
		for (j = 0; j < i; j++)
			copy[index++] = str[j];

		printf("%s\n", copy);
	}
}
