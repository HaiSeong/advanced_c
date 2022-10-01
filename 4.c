# include <stdio.h>
# include <string.h>

int  s_check(char  *p,  char  *q)
{
    int result = 0;
    for (char *temp = p; temp <= q; temp++) // 처음주소부터 끝 주소까지
    {
        if('a' <= *temp && *temp <= 'z') // 소문자면
            result++;
    }
    return (result); // 리턴
}
int main(void)
{
    int M; // M번 반복
    int K1, K2;
    char str[201]; // 200 문자
    int result;
    scanf("%d", &M); // 입력
    scanf("%d %d", &K1, &K2); // 입력
    getchar(); // 버퍼 비우기

    for(int i = 0; i < M; i++) // M번 반복
    {
        gets(str); // 입력
		int len = strlen(str); // 길이 구하기
		if (len < K2) // 길이보다 K2가 크면
        	result = s_check(&str[K1], str + len); // len을 주소로 전달
		else
	        result = s_check(&str[K1], &str[K2]); // 괜찮은 경우는k2전달
        if (result != 0) // 0이면 출력 안함
            printf("%d\n", result);
        fflush(stdin);
    }
}
