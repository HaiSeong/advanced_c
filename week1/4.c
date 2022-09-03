
#include <stdio.h>

int main()
{
	int x[3];
	
	scanf("%d%d%d", x, x+1, x+2);

	if (*x <= *(x+1) && *(x+1) <= *(x+2) || *(x+2) <= *(x+1) && *(x+1) <= *x)
		printf("%d\n", *(x+1));
	else if (*(x+1) <= *x && *x <= *(x+2) || *(x+2) <= *x && *x <= *(x+1))
		printf("%d\n", *x);
	else
		printf("%d\n", *(x+2));
}