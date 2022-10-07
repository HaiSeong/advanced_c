
#include <stdio.h>
#include <string.h>

typedef struct hotel_info // 구조체
{
    char name[31]; // 이름
    int grade; // 등급
    double review; // 평점
    double distance; // 거리
    char breakfast; // 조식여부
} hotel_info;

int in_hotel_info(struct hotel_info *p); // 원형 선언
void out_hotel_info(struct hotel_info *p, int N, int G, double D);

int main()
{
    hotel_info h_info[100]; //100 개의 배열

    int cnt = in_hotel_info(h_info); // 입력 및 갯수 받기
    int G;
    double D;
    scanf("%d%lf", &G, &D); // G, D 입력
    out_hotel_info(h_info, cnt, G, D); // 조건에 맞는 호텔들 정렬 후 출력
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
        h_info+=1; // 다음꺼로 넘어가기
    }
    return cnt; // 호텔의 수 리턴
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    hotel_info *best_hotel_info = 0; // null로 초기화
    hotel_info best_hotel_infos[100]; // 조건에 맞는 호텔을 담을 공간
    int cnt = 0; // 조건에 맞는 호텔 수

    for (hotel_info *h_info = p; h_info < p + N; h_info++) // 하나씩 탐색
    {
        if (h_info->grade >= G && h_info->distance <= D) // 조건이 맞으면
        {
            best_hotel_infos[cnt] = *h_info; // 복사
            cnt++;
        }
    }

    for (hotel_info *p = best_hotel_infos; p < best_hotel_infos + cnt - 1; p++) // 가장 큰 인덱스를 찾아서 앞으로 옮긴다.
	{
		hotel_info *max = p; // 맨 처음 값으로 초기화
		
		for (hotel_info *p2 = p + 1; p2 < best_hotel_infos + cnt; p2++) // 하나 뒤의 원소부터 검사
		{
			if (max->review < p2->review) // max보다 크면 바꾸기
				max = p2;
			else if (max->review == p2->review && strcmp(max->name , p2->name) > 0) // max보다 크면 바꾸기
				max = p2;
		}
		hotel_info temp = *p; // swap
		*p = *max; // swap
		*max = temp; // swap
	}

    for (hotel_info *bh_info = best_hotel_infos; bh_info < best_hotel_infos + cnt; bh_info++) // 하나씩 출력
        printf("%s %d %.1lf %.1lf %c", bh_info->name, bh_info->grade,
            bh_info->review, bh_info->distance, bh_info->breakfast); // 출력
}