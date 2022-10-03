
#include <stdio.h>

typedef struct time
{
    int h;
    int m;
    int s;
} time;

int main()
{
    time t1, t2, t3;
    scanf("%d%d%d", &(t1.h), &(t1.m), &(t1.s));
    scanf("%d%d%d", &(t2.h), &(t2.m), &(t2.s));
    
    t3.h = t2.h - t1.h;
    t3.m = t2.m - t1.m;
    t3.s = t2.s - t1.s;

    if (t3.m < 0)
    {
        t3.h -= 1;
        t3.m += 60;
    }
    if (t3.s < 0)
    {
        t3.m -= 1;
        t3.s += 60;
    }

    printf("%d %d %d\n", t3.h, t3.m, t3.s);
}