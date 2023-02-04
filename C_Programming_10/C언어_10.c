// 이진 파일 사용하기

// 이진 파일의 생성 (파일모드)
// rb, wb, ab

// 이진 파일 읽기 : fread()
// size_t fread(void *buffer, size_t size(sizeof(int)), size_t count, FILE *fp)

// 이진 파일 쓰기 : fwrite()
// size_t fwrite(void *buffer, size_t size(sizeof(int)), size_t count, FILE *fp)

// 이진 파일 읽기 쓰기 예제 코드 1
/*
#include <stdio.h>
#define SIZE 5

int main()
{
	int i;
	int buffer[SIZE] = { 10,20,30,40,50 };
	FILE* fp = NULL;

	fp = fopen("binary.bin", "wb");
	if (fp == NULL)
	{
		fprintf(stderr, "파일을 열 수 없음");
		return 1;
	}

	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);

	for (i = 0; i < SIZE; i++)
		buffer[i] = 0;

	fp = fopen("binary.bin", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "파일을 열 수 없음");
		return 1;
	}

	fread(buffer, sizeof(int), SIZE, fp);
	for (i = 0; i < SIZE; i++)
		printf("%d ", buffer[i]);

	fclose(fp);
	return 0;
}
*/

// 이진 파일 읽기 쓰기 예제 코드 2
/*
#include <stdio.h>
int main()
{
	FILE* src, * dst;
	char filename[100];
	char buffer[1024];
	int r_count;

	printf("이미지 파일 이름 : ");
	scanf("%s", filename);

	src = fopen(filename, "rb");
	dst = fopen("copy.jpg", "wb");
	if (src == NULL || dst == NULL)
	{
		fprintf(stderr, "파일 열기 오류\n");
		return 1;
	}

	while ((r_count = fread(buffer, 1, sizeof(buffer), src)) > 0)
	{
		int w_count = fwrite(buffer, 1, r_count, dst);
		if (w_count < 0)
		{
			fprintf(stderr, "파일 열기 오류\n");
			return 1;
		}
		if (w_count < r_count)
		{
			fprintf(stderr, "미디어 쓰기 오류\n");
			return 1;
		}
	}
	printf("copy.jpg로 이미지 파일 복사됨\n");
	fclose(src);
	fclose(dst);
	return 0;
}
*/

// 파일의 임의 접근

// 임의 접근 : 파일의 어느 위치에서든 쓰고 읽기
// 파일 위치 표시자를 강제로 이동시키면 임의 접근 가능
// 파일 읽기 모드 경우, 파일 위치 표시자는 0
// 파일 쓰기 모드 경우, 파일 위치 표시자는 파일의 끝을 가리킴(EOF)

// 파일의 임의 접근 함수 : fseek()
// int fseek(FILE *fp, long offset, SEEK_SET(0)) : 파일의 시작
// int fseek(FILE *fp, long offset, SEEK_CUR(1)) : 현재 위치
// int fseek(FILE *fp, long offset, SEEK_END(2)) : 파일의 끝

// fseek으로 하나 출력하고 나면 그 다음 칸 위치로 위치 지시자가 이동함

// 파일에서 단어 찾기 예제 코드
/*
#include <stdio.h>
int main()
{
	FILE* fp = NULL;
	char fname[100], word[100], buffer[1000];
	int count = 0;

	printf("파일 이름 : ");
	scanf("%s", fname);
	printf("탐색할 단어 : ");
	scanf("%s", word);

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	while (fgets(buffer, 1000, fp) != NULL)
	{
		count++;
		if (strstr(buffer, word) != NULL)
			printf("%s : %d %s\n", fname, count, buffer);
	}
	fclose(fp);
	return 0;
}
*/