
#include <stdio.h>

void PRT(int n, char *p);

int main()
{
	char str[100]; // 문자열을 저장
	char *p, *pmax; // 포인터 변수들
	int cnt = 0, max = 0; // 최대값을 저장핟기 위한 변수들

	p = str; 
	while (1) // str입력
	{
		scanf("%c", p);
		if (*p == '#') // #이면 종료
			break;
		p++;
	}

	p = str;
	while (1)
	{
		if (*p == '#') // #이면 종료
		{
			printf("\n");
			break;
		}

		if ('a' <= *p && *p <= 'z') // 소문자면 출력
		{
			printf("%c", *p); // 출력
			cnt++; 
			p++;
			if (max < cnt) // 맥스보다 크면 바꾸기
			{
				max = cnt;
				pmax = p - cnt; // 시작주소 저장
			}
		}
		else // 소문자가 아닐경우
		{
			cnt = 0;
			while (!('a' <= *p && *p <= 'z')) // 소문자 나올때까지 증가
			{
				if (*p == '#') // #이면 나가기
				{
					break;
				}
				p++;
			}
			if ('a' <= *p && *p <= 'z') // 다음 문자가 있으면 개행
				printf("\n");
		}
	}

	printf("%d %c\n", max, *pmax); // 출력
	PRT(max, pmax); // 출력함수
}

void PRT(int n, char *p)
{
	char *temp;

	for (temp = p; temp < p + n; temp++) // 하나씩 출력
	{
		printf("%c", *temp);
	}
	printf("\n");
}
