
#include <stdio.h>

typedef struct x
{
    int number;
    int index;
} X;

int main()
{
    int array[10];
    X x[10];

    for (int i = 0; i < 10; i++)
        scanf("%d", &(array[i]));

    for (int i = 0; i < 10; i++)
    {
        int cnt = 1;
        for (int j = 0; j < 10; j++)
            if (array[i] < array[j])
                cnt++;

        x[i].number = array[i];
        x[i].index = cnt;    
    }

    for (int i = 0; i < 10; i++)
    {
        if (x[i].index == 3)
            printf("%d ", x[i].number);
    }
    for (int i = 0; i < 10; i++)
    {
        if ( x[i].index == 7)
            printf("%d", x[i].number);
    }
}