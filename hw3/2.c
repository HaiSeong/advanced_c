
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[10]; // 이름
	int kor;
	int eng;
	int math;
	double avg;
}student;

struct average
{
	double kor;
	double eng;
	double math;
};

struct average calculate_avg(struct student *st, int N);
double read_data(struct student *st, int N);
double sort_score(struct student *st, int N);

int main()
{
	student s[49]; // 길이 50의 구조체 배열
	struct average avg;
	int N;
	int kcnt=0, ecnt=0, mcnt=0;

	scanf("%d", &N);


	avg = calculate_avg(s, N);

	for (student *p = s; p < s + N; p++)
	{
		if (p->kor < avg.kor)
			kcnt++;
		if (p->eng < avg.eng)
			ecnt++;
		if (p->math < avg.math)
			mcnt++;
	}

	printf("%.1lf %.1lf %.1lf\n", avg.kor, avg.eng, avg.math);
	printf("%d %d %d\n", kcnt, ecnt, mcnt);
}


struct average calculate_avg(struct student *st, int N)
{
	struct average avg;
	double k=0, e=0, m=0;

	for (struct student *p = st; p < st + N; p++)
	{
		k += p->kor;
		e += p->eng;
		m += p->math;
	}
	avg.kor = k / (double)N;
	avg.eng = e / (double)N;
	avg.math = m / (double)N;

	return avg;
}

double read_data(struct student *st, int N)
{
	for (student *p = st; p < st + N; p++)
	{
		scanf("%s", p->name); // 입력
		scanf("%d", &(p->kor)); // 입력
		scanf("%d", &(p->eng)); // 입력
		scanf("%d", &(p->math)); // 입력
	}
}

double sort_score(struct student *st, int N)
{
	// 영어 점수순으로 우선 정렬
	for (student *p = st; p < st + N - 1; p++)
	{
		student *max = p;
		student *p2;
		for (p2 = p + 1; p2 < st + N; p2++)
		{
			if (max->eng < p2->eng)
				max = p2;
		}
		max = p;
		p = p2;
		p2 = max;
	}

	// 국어 점수순으로 정렬
	for (student *p = st; p < st + N - 1; p++)
	{
		student *max = p;
		student *p2;
		for (p2 = p + 1; p2 < st + N; p2++)
		{
			if (max->kor < p2->kor)
				max = p2;
		}
		max = p;
		p = p2;
		p2 = max;
	}

	// 평균점수 순으로 정렬
	for (student *p = st; p < st + N - 1; p++)
	{
		student *max = p;
		student *p2;
		for (p2 = p + 1; p2 < st + N; p2++)
		{
			if (max->avg < p2->avg)
				max = p2;
		}
		max = p;
		p = p2;
		p2 = max;
	}
}