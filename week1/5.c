
#include <stdio.h>

int main()
{
	int arr[5];
	int cnt;
	int *p;
	int *p2;

	for(p=arr; p < arr+5; p++)
		scanf("%d", p);
	
	for(p=arr; p < arr+5; p++)
	{
		cnt = 1;
		for(p2=arr; p2 < arr+5; p2++)
		{
			if (*p < *p2)
				cnt++;
		}
		printf("%d=r%d ", *p, cnt);
	}
}