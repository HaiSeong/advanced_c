
#include <stdio.h>
#include <string.h>

int check(char *str);

int main()
{
	char str[101];
	int flag;

	scanf("%s", str);
	
	flag = check(str);
	
	printf("%d %d",strlen(str) , flag);
	
}

int check(char *str)
{
	int len, start, end;
	
	len = strlen(str);
	start = 0;
	end = len - 1;
	while (start < end)
	{
		if (str[start] != str[end])
		{
			return 0;
		}
		start++;
		end--;
	}

	return 1;
}