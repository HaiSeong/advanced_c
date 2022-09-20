
#include <stdio.h>

int del(char *str);

int main()
{
	char str[11];

	scanf("%s", str);
	del(str);
	printf("%s\n", str);
	
}

int del(char *str)
{
	char *p, *p2, *p3;
	int length, flag = 1;

	p = str;
	while (*p != '\0')
	{
		p++;
	}
	length = p - str;
	
	while (1)
	{
		for (p = str; *p != 0; p++)
		{
			flag = 1;
			for (p2 = p + 1; *p2 != 0; p2++)
			{
				if (*p == *p2)
				{
					for (p3 = p2; *(p3) != 0; p3++)
					{
						*p3 = *(p3 + 1);
						length--;
					}
					flag = 0;
					*p3 = '\0';
					break;
				}
			}
			if (flag == 0)
				break;
		}
		if (flag == 1)
			break;
		
	}
	return length;
	
}