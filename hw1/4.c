
#include <stdio.h>

void swap(int *pa, int *pb);
void ABC(int *start, int k);

int main()
{

	int room1[10], room2[10], all[20]; // 배열 선언
	int n = 0, m = 0, cnt; // 저장할 길이 선언
	int *temp; 

	temp = room1; // 초기화
	while (1)
	{
		scanf("%d", temp); // 입력
		if (*temp == -1)
			break;
		*(all + n) = *temp; // 복사
		n++;	
		temp++; // 인덱스 증가
	}

	temp = room2; // 초기화
	while (1)
	{
		scanf("%d", temp); // 입력
		if (*temp == -1)
			break;
		*(all + n + m) = *temp; // 복사
		m++;	
		temp++; // 인덱스 증가
	}
	
	cnt = n + m;
	for (temp = all; temp < all + n + m; temp++) // 
	{
		ABC(temp, cnt);
		cnt--;
	}

	for (temp = all; temp < all + n; temp++)
		printf("%d ", *temp);
	printf("\n");
	for (temp = all + m + n - 1; temp >= all + n; temp--)
		printf("%d ", *temp);
	printf("\n");
}

void swap(int *pa, int *pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void ABC(int *start, int k)
{
	int *temp;
	int max = *start;
	int *pmax = start;

	for (temp = start + 1; temp < start + k; temp++)
	{
		if (max < *temp)
		{
			max = *temp;
			pmax = temp;
		}
	}
	swap(pmax, start);
}