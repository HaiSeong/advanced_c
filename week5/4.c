
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[20];
    int score1;
    int score2;
    int score3;
} student;

int main()
{
    student S[5];
    char temp_name[20];
    int temp_score1, temp_score2,temp_score3, N;
    double avg, sum = 0;

    scanf("%d", &N);

    for (int i=0; i < N; i++)
    {
        sum = 0;
        avg = 0;
        scanf("%s%d%d%d", temp_name, &temp_score1, &temp_score2, &temp_score3);
        strcpy(S[i].name, temp_name);
        S[i].score1 = temp_score1;
        S[i].score2 = temp_score2;
        S[i].score3 = temp_score3;
        sum = S[i].score1 + S[i].score2 + S[i].score3;
        avg = sum / 3.0;

        printf("%s %.1lf", S[i].name, avg);

        if (avg > 90)
            printf(" A");
        else if (avg > 80)
            printf(" B");
        else if (avg > 70)
            printf(" C");
        else
            printf(" F");

        printf("\n");
    }
}