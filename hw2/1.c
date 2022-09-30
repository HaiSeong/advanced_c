
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[101], str2[101]; // n == 20 이고 문자열 "11111111111111111111" 이 들어오면 "A"를 100개 저장해야함
	char temp[101] = ""; // 임시로 저장할 문자열
	int N;

	gets(str1); // 입력
	gets(str2); // 입력

	for (N = 1; N <= 10; N++) // str1을 str2로 만들수 있는가
	{
		int i = 0; // str의 인덱스
		int index = 0; // temp의 인덱스
		while (str1[i] != '\0') // 문자열 끝까지 탐색
		{
			char c = str1[i];
			if ('A' <= c && c <= 'Z') // 대문자
			{
				c += N; // N번째 뒤 문자
				temp[index] = c; // 입력
				index++;
			}
			else if ('a' <= c && c <= 'z') // 소문자
			{
				c -= N; // N번째 앞 문자
				temp[index] = c; // 입력
				index++;
			}
			else if ('0' <= c && c <= '9') // 숫자
			{
				char c2 = str1[i+1]; // 다음을 읽어봄
				int num; // 반복할 횟수
				if ('0' <= c2 && c2 <= '9') // 다음 문자도 숫자인 경우
				{
					num = (c - '0') * 10 + (c2 - '0'); // 두자리 수 계산
					i++; // 한자리 더 읽었으므로
				}
				else
				{
					num = c - '0'; // 한자리수 계산
				}
				c = 'A' + num - 1; // 출력할 문자
				for (int k = 0; k < N; k++) // num번 수행 
				{
					temp[index] = c; // c 저장
					index++;
				}
			}
			else // 다른 경우
			{
				temp[index] = ' '; // 공백 넣기
				index++;
			}
			i++;
		}
		temp[index] = '\0';

		if (strcmp(temp, str2) == 0) // 두 문자열이 같으면
		{
			printf("1\n"); // 1
			return 0;
		}
	}
	
	for (N = 1; N <= 10; N++) // str2를 str1로 만들수 있는가
	{
		int i = 0; // str의 인덱스
		int index = 0; // temp의 인덱스
		while (str2[i] != '\0') // 문자열 끝까지 탐색
		{
			char c = str2[i];
			if ('A' <= c && c <= 'Z') // 대문자
			{
				c += N; // N번째 뒤 문자
				temp[index] = c; // 입력
				index++;
			}
			else if ('a' <= c && c <= 'z') // 소문자
			{
				c -= N; // N번째 앞 문자
				temp[index] = c; // 입력
				index++;
			}
			else if ('0' <= c && c <= '9') // 숫자
			{
				char c2 = str2[i+1]; // 다음을 읽어봄
				int num; // 반복할 횟수
				if ('0' <= c2 && c2 <= '9') // 다음 문자도 숫자인 경우
				{
					num = (c - '0') * 10 + (c2 - '0'); // 두자리 수 계산
					i++; // 한자리 더 읽었으므로
				}
				else
				{
					num = c - '0'; // 한자리수 계산
				}
				c = 'A' + num - 1; // 출력할 문자
				for (int k = 0; k < N; k++) // num번 수행 
				{
					temp[index] = c; // c 저장
					index++;
				}
			}
			else // 다른 경우
			{
				temp[index] = ' '; // 공백 넣기
				index++;
			}
			i++;
		}
		temp[index] = '\0';

		if (strcmp(temp, str1) == 0) // 두 문자열이 같으면
		{
			printf("2\n"); // 2
			return 0;
		}
	}
	
	printf("0\n"); // 불가능한 경우
}