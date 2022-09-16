
#include <stdio.h>

int passengerN(int n);
void rebooking(int *ar, int n);
int changeseat(int *ar, int n);

int main()
{
	int n; // 승객의 수
	int array[21]; // 좌석 번호를 저장할 배열
	int *p;
	int is5;
	
	scanf("%d", &n);
	for (p = array; p < array + n; p++)
	{
		scanf("%d", p);
	}
	
	is5 = passengerN(n); // 5명 미만인지 검사하는 함수
	printf("%d\n", is5); // 출력
	if (is5 == -1) // -1이라면 종료
		return 0;

	rebooking(array, n); // 승객 재배치

	for (p = array; p < array + n; p++)	 // 승객 수가 충분하면 최종 좌석 예약 결과를 출력
		printf("%d ", *p);
	
}

int passengerN(int n) // 5명 미만인지 검사하는 함수
{
	if (n < 5) // 5명 미만이면 -1 출력
		return -1;

	return 0;
}

void rebooking(int *ar, int n)
{
	int *p;
	int *p2;

	for (p = ar; p < ar + n; p++) // 앞에서 부터 탐색
	{
		for (p2 = p + 1; p2 < ar + n ; p2++) // 이전 승객들의 번호 탐색
		{
			if (*p2 == *p) // 증복되는 경우가 있으먄
			{
				*p2 = changeseat(ar, n); // 가능한 가장 작은 변수 입력
			}
		}
	}
}

int changeseat(int *ar, int n)
{
	int i;
	int *p; // 탐색준비

	for (i = 1; i<=21; i++) // 1부터 탐색
	{
		for (p = ar; p < ar + n; p++) // 배열을 탐색
		{
			if (*p == i) // 이미 i가 있는 경우
				break;
		}
		if (p == ar + n) // 반복문이 끝까지 돌은 경우 : 증복되는 숫자가 없는 경우
			break;
	}
	
	return i; // 리턴
}