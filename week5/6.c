
#include <stdio.h>
#include <string.h>

typedef struct student
{
	int gender;
	int weight;
	int height;
} student;

int main()
{
    student S[10];
    int temp_gender, temp_weight, temp_height, N;
	int pivot1, pivot2; // p1보다 작으면 가장 가벼운 그룹, p2보다 크면 가장 무거운 그룹
	int cnt1=0, cnt2=0, cnt3=0;

    scanf("%d", &N);

    for (int i=0; i < N; i++)
    {
        scanf("%d%d%d", &temp_gender, &temp_weight, &temp_height);
        S[i].gender = temp_gender;
        S[i].weight = temp_weight;
        S[i].height = temp_height;
    }

	for (int i = 0; i < N; i++)
	{
		if (S[i].gender == 1)
		{
			pivot1 = 60;
			pivot2 = 70;
		}
		else
		{
			pivot1 = 50;
			pivot2 = 60;
		}

		if (S[i].weight < pivot1) // 저체중
		{
			if (S[i].height < 165) // 작은키
				cnt1++;
			else if (S[i].height >= 175) // 큰기
				cnt3++;
			else // 보통키
				cnt2++;
		}
		else if (S[i].weight >= pivot2) // 과체중
		{
			if (S[i].height < 165) // 작은키
				cnt2++;
			else if (S[i].height >= 175) // 큰기
				cnt1++;
			else // 보통키
				cnt3++;
		}
		else // 보통 체중
		{
			if (S[i].height < 165) // 작은키
				cnt3++;
			else if (S[i].height >= 175) // 큰기
				cnt2++;
			else // 보통키
				cnt1++;
		}
	}
	printf("%d %d %d\n", cnt1, cnt2, cnt3);
	return 0;
}