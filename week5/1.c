
#include <stdio.h>

typedef struct vector
{
    int x;
    int y;
    int z;
} V;

int main()
{
    V V1, V2, V3;
    scanf("%d%d%d", &(V1.x), &(V1.y), &(V1.z));
    scanf("%d%d%d", &(V2.x), &(V2.y), &(V2.z));
    
    V3.x = V1.x * V2.x;
    V3.y = V1.y * V2.y;
    V3.z = V1.z * V2.z;

    printf("%d %d %d\n", V3.x, V3.y, V3.z);
    printf("%d\n", V3.x + V3.y + V3.z);
}