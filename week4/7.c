
#include <stdio.h>

void putstr(int n);

int main()
{
	//one two three four five six seven eight nine
	// : 천 THO 백 HUN 십 TEN
	int N;
	int tho, hun, ten, one;

	scanf("%d", &N);
	tho = N/1000;
	hun = N/100%10;
	ten = N/10%10;
	one = N%10;

	if (tho > 0)
	{
		putstr(tho);
		printf("THO ");
	}
	if (hun > 0)
	{
		putstr(hun);
		printf("HUN ");
	}
	if (ten > 0)
	{
		putstr(ten);
		printf("TEN ");
	}
	if (one > 0)
	{
		putstr(one);
	}
}

void putstr(int n)
{
	switch (n)
	{
	case 1:
		printf("one ");
		break;
	case 2:
		printf("two ");
		break;
	case 3:
		printf("three ");
		break;
	case 4:
		printf("four ");
		break;
	case 5:
		printf("five ");
		break;
	case 6:
		printf("six ");
		break;
	case 7:
		printf("seven ");
		break;
	case 8:
		printf("eight ");
		break;
	case 9:
		printf("nine ");
		break;
	
	default:
		break;
	}
}