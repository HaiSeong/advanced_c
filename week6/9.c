
#include <stdio.h>

typedef struct result
{
    int score1;
    int score2;
    int standard;
    int diff;
    char pass;
} Result;

void passorfail(Result *r);

int main()
{
    Result r;

    scanf("%d%d%d", &(r.score1), &(r.score2), &(r.standard));

    passorfail(&r);

    printf("%d %c\n", r.diff, r.pass);
}

void passorfail(Result *r)
{
    r->diff = r->score1 - r->score2;

    if (0 <= r->diff && r->diff <= 15)
        r->pass = 'P';
    else
        r->pass = 'F'; 
}