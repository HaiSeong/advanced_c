
#include <stdio.h>

int *MAX(int ar[]);
int *MIN(int ar[]);

int main()
{
	int ar[100]; // 100를 담을 수 있는 배열 선언
	int n; // 반복 횟수
	int *pmax, *pmin; // 최대 최소의 주소를 저장할 변수들
	int *temp, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) // n 번 반복
	{
		temp = ar;
		while (1)
		{
			scanf("%d", temp); // 입력
			if (*temp == 0) // 0인 경우 종료
				break ;
			temp++;
		}
		
		pmax = MAX(ar); // 최대 최소값 주소 저장
		pmin = MIN(ar);
		
		if (pmax > pmin) // pmax 를 시작주소로 사용 pmin보다 뒷주소라면 바꿔주기
		{
			temp = pmax; // 스왑
			pmax = pmin;
			pmin = temp;
		}

		if (pmin - pmax <= 1) // 출력할 것이 없는 경우
		{
			printf("none\n"); // none 출력
			continue;
		}

		for (temp = pmax + 1; temp < pmin; temp++) // 사이값들을 출력
		{
			printf("%d ", *temp);
		}
		printf("\n");
	}
}

int *MAX(int ar[])
{
	int *p; // 탐색을 위한 포인터 변수
	int max; // 최대값을 저장할 정수형 변수
	int *pmax; // 최대값을 주소를 저장할 포인터 변수

	p = ar; // 탐색을 위한 준비
	max = *p; // 최대값은 우선 가장 처음 인덱스로 초기화
	pmax = p; 
	p++; // 다음 노드부터 탐색
	while (*p != 0) // 0이 아닐때 까지
	{
		if (max < *p) // 더 큰 값을 찾으면 
		{
			max = *p; // 최대값 바꾸기
			pmax = p;
		}
		p++; // 다음 주소로 이동
	}
	
	return pmax; // 리턴
}

int *MIN(int ar[])
{
	int *p; // 탐색을 위한 포인터 변수
	int min; // 최소값을 저장할 정수형 변수
	int *pmin; // 최소값을 주소를 저장할 포인터 변수

	p = ar; // 탐색을 위한 준비
	min = *p; // 최소값은 우선 가장 처음 인덱스로 초기화
	pmin = p;
	p++; // 다음 노드부터 탐색
	while (*p != 0) // 0이 아닐때 까지
	{
		if (min > *p) // 더 작은 값을 찾으면 
		{
			min = *p; // 최소값 바꾸기
			pmin = p;
		}
		p++; // 다음 주소로 이동
	}
	
	return pmin; // 리턴
}