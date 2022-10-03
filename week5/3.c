
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[10];
    int score;
} student;

int main()
{
    student S[5];
    char temp_name[10];
    int temp_score;
    double avg, sum = 0;

    for (int i=0; i < 5; i++)
    {
        scanf("%s%d", temp_name, &temp_score);
        strcpy(S[i].name, temp_name);
        S[i].score = temp_score;
        sum += S[i].score;
    }
    avg = sum / 5.0;
     for (int i=0; i < 5; i++)
    {
        if (S[i].score <= avg)
            printf("%s\n", S[i].name);
    }
}