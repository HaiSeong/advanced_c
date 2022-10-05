
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[10];
	char id[11];
	char grade;
}student;


int main()
{
	student s[5]; // 길이 5의 구조체 배열
	char finding[10];
	char finding_year[5];
	char finding_grade;

	for (int i=0; i < 5; i++) // 5번 수행
	{
		scanf("%s", s[i].name); // 입력
		scanf("%s", s[i].id); // 입력
		getchar();
		scanf("%c", &(s[i].grade)); // 입력
	}

	scanf("%s", finding); // 검색할 이름

	for (int i=0; i < 5; i++)
	{
		if (strcmp(finding, s[i].name) == 0)
		{
			strncpy(finding_year, s[i].id, 4);
			finding_grade = s[i].grade;
			break;
		}
	}

	int cnt = 0;
	for (int i=0; i < 5; i++)
	{
		if (finding_grade == s[i].grade && strncmp(finding_year, s[i].id, 4) == 0)
		{
			if (strcmp(finding, s[i].name) != 0)
			{
				printf("%s ",s[i].name);
				cnt++;
			}
		}
	}
	if (cnt == 0)
		printf("0");
	int num = atoi(finding_year);
	printf("\n%d %d\n", num, num%131);
}