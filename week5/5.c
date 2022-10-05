
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[8];
    int score1;
    int score2;
    int score3;
	double avg;
} student;

int main()
{
    student S[50];
	student *p;
    int N;
    double sum = 0;

    scanf("%d", &N);

    for (p = S; p < S + N; p++)
    {
        sum = 0;
        scanf("%s%d%d%d", p->name, &(p->score1), &(p->score2), &(p->score3));
        sum = p->score1 + p->score2 + p->score3;
        p->avg = sum / 3.0;
    }

    for (p = S; p < S + N; p++)
	{
        printf("%s %.1lf", p->name, p->avg);

        if (p->avg >= 90)
            printf(" A");
        else if (p->avg >= 80)
            printf(" B");
        else if (p->avg >= 70)
            printf(" C");
        else
            printf(" D");

        printf("\n");
	}
	return 0;
}