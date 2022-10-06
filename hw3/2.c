
#include <stdio.h>
typedef struct student
{
	char name[21]; // 이름
	int kor; // 국어
	int eng; // 영어
	int math; // 수학
	double avg; // 평균
}student;

void read_data(struct student *st, int N); // 원형 선언
void sort_score(struct student *st, int N); // 원형 선언
student *select_out(student *st1, student *st2, int N); // 원형 선언

int main()
{
	student st1[49]; // 길이 49의 구조체 배열
	student st2[49]; // 길이 49의 구조체 배열
	int N;

	scanf("%d", &N); // N입력

	read_data(st1, N); // st1에 입력하기
	read_data(st2, N); // st2에 입력하기

	sort_score(st1, N); // 정렬하기
	sort_score(st2, N); // 정렬하기

	student *select = select_out(st1, st2, N); // 중앙값이 더 큰것

	for(student *p = select; p < select + N; p++) // 하나씩 출력
	{
		printf("%s %d %d %d %.1f\n", p->name, p->kor, p->eng, p->math, p->avg); // 출력
	}
	return 0;
}

void read_data(struct student *st, int N)
{
	for (student *p = st; p < st + N; p++) // 하나씩 탐색
	{
		scanf("%s", p->name); // 입력
		scanf("%d", &(p->kor)); // 입력
		scanf("%d", &(p->eng)); // 입력
		scanf("%d", &(p->math)); // 입력
		p->avg = (p->kor + p->eng + p->math)/3.0; // 평균계산
	}
}

void sort_score(struct student *st, int N)
{
	// 평균점수 순으로 정렬 -> 같으면 한국어 점수 -> 같으면 영어점수
	for (student *p = st; p < st + N - 1; p++) // 가장 큰  인덱스를 찾아서 앞으로 옮긴다.
	{
		student *max = p; // 맨 처음 값으로 초기화
		
		for (student *p2 = p + 1; p2 < st + N; p2++) // 하나 뒤의 원소부터 검사
		{
			if (max->avg < p2->avg) // max보다 크면 바꾸기
				max = p2;
			else if (max->avg == p2->avg && max->kor < p2->kor) // max보다 크면 바꾸기
				max = p2;
			else if (max->avg == p2->avg && max->kor == p2->kor && max->eng < p2->eng) // max보다 크면 바꾸기
				max = p2;
		}
		student temp = *p; // swap
		*p = *max; // swap
		*max = temp; // swap
	}
}

student *select_out(student *st1, student *st2, int N)
{
	if ((st1[N/2]).avg >= (st2[N/2]).avg) // 1의 중앙값이 더 크면
		return st1; // 1리턴
	else // 2가 더 크면
		return st2; // 2리턴
}