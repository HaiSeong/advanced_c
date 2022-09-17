
#include <stdio.h>

int main()
{
	char str1[41], str2[21];
	int i, j, s1len, s2len, flag = 1, index;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &index);
	
	i = 0;
	while (str1[i] != '\0')
		i++;
	s1len = i;

	i = 0;
	while (str2[i] != '\0')
		i++;

	s2len = i;
	
	for (i = s1len - 1; i >= index; i--)
		str1[i + s2len] = str1[i];
	
	for (i = index, j = 0; j < s2len; i++, j++)
		str1[i] = str2[j];
	str1[s1len + s2len] = '\0';
	printf("%s\n", str1);
}
