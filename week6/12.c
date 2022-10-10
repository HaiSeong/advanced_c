
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[10];
    int score1;
    int score2;
    int score3;
    double avg;
} student;


void read_data(student S[]);
void cal_avg(student S[]);
void sort(student S[]);
void print_score(student S[]);

int main()
{
    student S[10];

    read_data(S);
    cal_avg(S);
    sort(S);
    print_score(S);
}

void read_data(student S[])
{
    char temp_name[10];
    int temp_score1;
    int temp_score2;
    int temp_score3;

    for (int i=0; i< 10; i++)
    {
        scanf("%s%d%d%d", temp_name, &temp_score1, &temp_score2, &temp_score3);
        strcpy(S[i].name, temp_name);
        S[i].score1 = temp_score1;
        S[i].score2 = temp_score2;
        S[i].score3 = temp_score3;
    }
}

void cal_avg(student S[])
{
    for (int i=0; i< 10; i++)
    {
        S[i].avg = (S[i].score1 + S[i].score2 + S[i].score3) / 3.0;
    }
}

void sort(student S[])
{
    for (student *p = S; p < S + 9; p++) // 가장 큰 인덱스를 찾아서 앞으로 옮긴다.
	{
		student *max = p; // 맨 처음 값으로 초기화
		
		for (student *p2 = p + 1; p2 < S + 10; p2++) // 하나 뒤의 원소부터 검사
		{
			if (max->avg < p2->avg) // max보다 크면 바꾸기
				max = p2;
		}
		student temp = *p; // swap
		*p = *max; // swap
		*max = temp; // swap
	}
}

void print_score(student S[])
{
    printf("%s %.2lf\n", S[0].name, S[0].avg);
    printf("%s %.2lf\n", S[9].name, S[9].avg);
    printf("%s %.2lf\n", S[7].name, S[7].avg);
    printf("%s %.2lf\n", S[8].name, S[8].avg);
    printf("%s %.2lf\n", S[9].name, S[9].avg);
}