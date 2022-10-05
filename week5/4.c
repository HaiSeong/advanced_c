
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[20];
    int score1;
    int score2;
    int score3;
	double avg;
} student;

int main()
{
    student S[20];
    char temp_name[20];
    int temp_score1, temp_score2,temp_score3, N;
    double sum = 0;

    scanf("%d", &N);

    for (int i=0; i < N; i++)
    {
        sum = 0;
        scanf("%s%d%d%d", temp_name, &temp_score1, &temp_score2, &temp_score3);
        strcpy(S[i].name, temp_name);
        S[i].score1 = temp_score1;
        S[i].score2 = temp_score2;
        S[i].score3 = temp_score3;
        sum = S[i].score1 + S[i].score2 + S[i].score3;
        S[i].avg = sum / 3.0;
    }

	for (int i = 0; i < N; i++)
	{
        printf("%s %.1lf", S[i].name, S[i].avg);

        if (S[i].avg >= 90)
            printf(" A");
        else if (S[i].avg >= 80)
            printf(" B");
        else if (S[i].avg >= 70)
            printf(" C");
        else
            printf(" F");

        printf("\n");
	}
	return 0;
}