
#include <stdio.h>
#include <string.h>

typedef struct hotel_info
{
    char name[31];
    int grade;
    double review;
    double distance;
    char breakfast;
} hotel_info;

int in_hotel_info(struct hotel_info *p);
void out_hotel_info(struct hotel_info *p, int N, int G, double D);

int main()
{
    hotel_info h_info[100];

    int cnt = in_hotel_info(h_info);
    int G;
    double D;
    scanf("%d%lf", &G, &D);
    out_hotel_info(h_info, cnt, G, D);
}


int in_hotel_info(struct hotel_info *p)
{
    int cnt = 0; // 호텔의 수

    hotel_info *h_info = p; // 탐색 포인터
    while (1)
    {
        scanf("%s", h_info->name); // 이름
        if (strcmp(h_info->name, "0") == 0) // 0 입력시 종료
            break;

        scanf("%d", &(h_info->grade)); // 등급
        scanf("%lf", &(h_info->review)); // 평판도
        scanf("%lf", &(h_info->distance)); // 거리
        scanf(" %c", &(h_info->breakfast)); // 조식포함여부
        
        cnt++;
        h_info+=1;
    }
    return cnt; // 호텔의 수 리턴
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    hotel_info *best_hotel_info = 0;
    hotel_info * best_hotel_infos[100];
    int cnt = 0;

    for (hotel_info *h_info = p; h_info < p + N; h_info++)
    {
        if (h_info->grade >= G && h_info->distance <= D)
        {
            best_hotel_infos[cnt] = h_info;
            cnt++;
        }
    }

    for (hotel_info *p = best_hotel_infos[0]; p < best_hotel_infos[0] + cnt - 1; p++) // 가장 큰  인덱스를 찾아서 앞으로 옮긴다.
	{
		hotel_info *max = p; // 맨 처음 값으로 초기화
		
		for (hotel_info *p2 = p + 1; p2 < best_hotel_infos[0] + cnt; p2++) // 하나 뒤의 원소부터 검사
		{
			if (max->review < p2->review) // max보다 크면 바꾸기
				max = p2;
			else if (max->review == p2->review && (max->name , p2->name) > 0) // max보다 크면 바꾸기
				max = p2;
		}
		hotel_info temp = *p; // swap
		*p = *max; // swap
		*max = temp; // swap
	}

    for (hotel_info *p = best_hotel_infos; p < best_hotel_infos + cnt; p++)
        printf("%s %d %.1lf %.1lf %c", best_hotel_info->name, best_hotel_info->grade,
            best_hotel_info->review, best_hotel_info->distance, best_hotel_info->breakfast);
}