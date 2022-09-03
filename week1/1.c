
#include <stdio.h>

int main()
{
	int x, y, z;
	int *px, *py, *pz, *tmp ; // tmp는 포인터이다

	px = &x;
	py = &y;
	pz = &z;

	scanf("%d%d%d", px, py, pz);

	tmp = pz;
	pz = py;
	py = px;
	px = tmp;

	printf("%d %d %d\n", *px, *py, *pz);
}