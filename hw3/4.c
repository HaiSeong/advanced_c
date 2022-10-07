
#include <stdio.h>

typedef struct parking_info
{
    int number; // ◦ 차량 번호: 정수형 (4자리)
    int phone; // ◦ 고객 전화번호: 정수형 (8자리)
    char SorD; // ◦ 상품: 문자형 (S 혹은 D)
    char isS; // ◦ 정기권 가입유무: 문자형 (Y 혹은 N) 일일권은 해당사항 없음
    int type; // ◦ 종류: 정기권(S) -> 정수형 { 7 / 30 / 180 } 일(type); 일일권은 해당사항 없음
    int minute; // ◦ 주차시간 (분): 정수형
    int pay; // ◦ 요금 (원): 실수형(double)
} parking_info;

void input(struct parking_info *p, int N);
void compute(struct parking_info *p);
void display(struct parking_info *p, int N);
void bike_info_sort(struct parking_info *p, int N);

// 4) main 함수
// ◦ input 함수를 호출하여 주차장 이용정보를 입력 받음
// ◦ compute 함수를 호출하여 주차장 이용료 계산
// ◦ display 함수를 호출하여 계산한 요금을 출력한다. (출력예시와 같이 ‘차량번호’, ‘고객전화’,
// ‘S/D’, ‘주차료’를 출력) (단, 요금은 소수점이하는 표시하지 않음)
int main()
{
    parking_info p_info[100]; // 100개의 구조체 배열
    int N;
    int scnt = 0, dcnt = 0; // 합계를 저장할 변수

    scanf("%d", &N); // N 입력
    input(p_info, N); // 입력 함수
    for (parking_info *p = p_info; p < p_info + N; p++) // 반복문
    {
        compute(p); // 계산함수
    }
    bike_info_sort(p_info, N); // 정렬 함수
    display(p_info, N); // 출력 함수

    for (parking_info *p = p_info; p < p_info + N; p++) // 반복문
    {
        if (p->SorD == 'S') // S면 scnt에 더하기
            scnt += p->pay;
        else if (p->SorD == 'D') // D면 dcnt에 더하기
            dcnt += p->pay;
    }
    printf("%d %d %d\n", dcnt, scnt, dcnt+scnt); // 합 출력
}

void input(struct parking_info *p, int N)
{
    for (parking_info *p_info = p; p_info < p + N; p_info++)
    {
        scanf("%d %d %c", &(p_info->number), &(p_info->phone), &(p_info->SorD));
        if (p_info->SorD == 'S')
        {
            scanf(" %c", &(p_info->isS));
            scanf("%d%d", &(p_info->type), &(p_info->minute));
        }
        else
        {
            p_info->isS = 'N';
            scanf("%d", &(p_info->minute));
        }
        p->pay = 0;
    }
}

void compute(struct parking_info *p)
{

    p->minute -= 60 * 4; // 기본시간 4시간 -> 4 * 60분
    if (p->SorD == 'S') // S인 경우
    {
        if (p->isS == 'N') // 정기권을 지금 구매하는 경우
        {
            switch (p->type) // 타입에 따라서 돈 추가
            {
            case 7: p->pay+=30000; break;
            case 30: p->pay+=100000; break;
            case 180: p->pay+=500000; break;
            }
        }
    }
    else // 일일권인경우
    {
        p->pay += 5000;
    }
    while (p->minute >= 10) // 10분 초과시마다 돈 추가
    {
        p->minute -= 10; // 10분 삭제
        p->pay += 200; // 200원 추가
    }
}

void display(struct parking_info *p, int N) // 출력 함수
{
    for (parking_info *p_info = p; p_info < p + N; p_info++) // 반복문
    {
        printf("%d %d %c %d\n", p_info->number, p_info->phone, p_info->SorD, p_info->pay); // 출력
    }
}

void bike_info_sort(struct parking_info *p, int N) // 정렬 함수
{
    for (parking_info *p_info = p; p_info < p + N - 1; p_info++) // 가장 큰 인덱스를 찾아서 앞으로 옮긴다.
	{
		parking_info *max = p_info; // 맨 처음 값으로 초기화
		
		for (parking_info *p_info2 = p_info + 1; p_info2 < p + N; p_info2++) // 하나 뒤의 원소부터 검사
		{
			if (max->SorD > p_info2->SorD) // S가 D보다 앞에 있으면 바꾸기
				max = p_info2;
			else if (max->SorD == p_info2->SorD && max->number > p_info2->number) // max보다 크면 바꾸기
				max = p_info2;
		}
		parking_info temp = *p_info; // swap
		*p_info = *max; // swap
		*max = temp; // swap
	}
}