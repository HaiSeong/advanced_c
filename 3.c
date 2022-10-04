
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100]; // nul 을 포함한 길이 100
	char str2[100];

	gets(str1); // 입력
	scanf("%s", str2);

	int cnt = 0; // 갯수 초기화
	int i = 0; // 인덱스 변수  
	int len1 = strlen(str1); // 첫문장의 길이
	int len2 = strlen(str2); // 두번째 길이
	while (str1[i] != '\0' && i + len2 <= len1) // 문장 끝이거나 더 이상 탐색할 필요가 없을때  
	{
		if (strncmp(str1 + i, str2, len2) == 0) // 비교
		{
			if ((i == 0 || str1[i - 1] == ' ' || str1[i - 1] == '.') && (i + len2 == len1 || str1[i + len2] == ' '|| str1[i + len2] == '.' ))
				cnt++; // 문장의 가장처음이거나 앞글자가 공백  또는  .     이고     문장의 가장 마지막 이거나 공백이나 .
		}
		i++; // 인덱스 증가
	}
	
	printf("%d\n", cnt); // 출력
}