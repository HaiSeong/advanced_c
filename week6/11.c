
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[10];
    int score;
} student;

student *select_min(student *S);

int main()
{
    student S[5], *result;
    char temp_name[10];
    int temp_score;

    for (int i=0; i < 5; i++)
    {
        scanf("%s%d", temp_name, &temp_score);
        strcpy(S[i].name, temp_name);
        S[i].score = temp_score;
    }
    
    result = select_min(S);
    
    printf("%s %d\n", result->name, result->score);
}

student *select_min(student *S)
{
    int min = 0;
    int i;
    for (i=1; i < 5; i++)
    {
        if (S[i].score < S[min].score)
            min = i;
    }

    return S + min;
}