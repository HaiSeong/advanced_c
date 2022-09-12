
#include <stdio.h>

void strcopy(char a[], char b[]);

int main()
{
	char a[6], b[6];
	char *pb;

	scanf("%s", a);
	strcopy(a, b);
	for (pb = b; pb < b + 6; pb++)
		printf("%c", *pb);
	printf("\n");
}

void strcopy(char a[], char b[])
{
	char *pa;
	char *pb;
	
	for (pa = a, pb = b; pa < a + 6; pa++, pb++)
		*pb = *pa;
}
