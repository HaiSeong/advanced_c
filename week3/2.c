
#include <stdio.h>

int main()
{
	char str[10], copy[10];
	int i, j;

	scanf("%s", str);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	copy[i] = '\0';
	for (j = i-1, i= 0; j>=0; j--, i++)
	{
		copy[j] = str[i];
	}
	printf("%s\n", copy);
}
