
#include <stdio.h>

typedef struct time
{
    int y;
    int m;
    int d;
} Time;

Time *select_min(Time *t1, Time *t2);

int main()
{
    Time *t, t1, t2;

    scanf("%d/%d/%d", &(t1.y), &(t1.m), &(t1.d));
    scanf("%d/%d/%d", &(t2.y), &(t2.m), &(t2.d));

    t = select_min(&t1, &t2);

    printf("%d/%d/%d\n", t->y, t->m, t->d);
}

Time *select_min(Time *t1, Time *t2)
{
    if (t1->y == t2->y)
    {
        if (t1->m == t2->m)
        {
            if (t1->d < t2->d)
                return t1;
            else
                return t2;
        }
        else if (t1->m < t2->m)
            return t1;
        else
            return t2;
    }
    else if (t1->y < t2->y)
        return t1;
    else
        return t2;
}