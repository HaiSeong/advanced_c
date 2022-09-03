
#include <stdio.h>

int main()
{
	char *str;
	int i;

	scanf("%s", str);
	 
	i = 0;
	while (*(str + i) != '#')
		i++;
	i--;
	while (i >= 0)
	{
		printf("%c", *(str + i));
		i--;
	}
	printf("\n");
}