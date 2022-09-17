
#include <stdio.h>

int main()
{
	char str[21];
	int i;

	scanf("%s", str);
	i = 0;
	while (str[i] != '\0')
	{
		if ('a'<=str[i] && str[i]<='z')
			printf("%c", str[i]);
		i++;
	}
	
}
