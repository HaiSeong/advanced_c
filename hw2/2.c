
#include <stdio.h>
#include <string.h>

int main()
{
	char strs[20][200];
	char temp[201]; // 입력받을 문자열
	char add[200];

	gets(temp); // 입력
	gets(add); // 추가할 단어 입력
	int index = 0; // temp를 읽을 인덱스
	int i = 0; // 각 단어의 인덱스
	while (temp[index] != '\0')
	{
		int j = 0; // 단어안의 문자를 저장할 인덱스
		while (temp[index] != ' ' && temp[index] != '\0')
		{
			strs[i][j] = temp[index]; // strs에 저장
			j++; // j증가
			index++; // index증가
		}
		if (j > 0) // 단어가 있으면 
		{
			strs[i][j] = '\0'; // 뒤에 널문자 추가
			i++; // 단어 추가
		}
		else
			index++;
	}

	int flag = 1; // 중복이면 0 아니면 1
	int cnt = i; // cnt : 단어의 갯수
	for (i = 0; i < cnt; i++)
	{
		printf("%s\n", strs[i]); // 출력
		if (strcmp(strs[i], add) == 0)
			flag = 0; // 중복이면 0
	}
	if (flag == 1)
	{
		printf("%s\n", add);
		int j = 0;
		while (strs[i][j] != '\0')
		{
			strs[i][j] = add[j];
			j++;
		}
		strs[i][j] = '\0';

		cnt = i + 1;
	}

	for (i = 0; i< cnt - 1; i++) // 정렬
	{
		int min = i;
		for (int j = i+1; j < cnt; j++) // 오름차순 정렬
		{
			if (strcmp(strs[min], strs[j]) > 0)
				min = j;
		}
		strcpy(temp, strs[i]); // 빠른 문자열을 앞으로 옮김
		strcpy(strs[i], strs[min]);
		strcpy(strs[min], temp);
	}

	for (i = 0; i < cnt; i++)
		printf("%s ", strs[i]); // 출력
	

}