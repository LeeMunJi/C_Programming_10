// ���� ���� ����ϱ�

// ���� ������ ���� (���ϸ��)
// rb, wb, ab

// ���� ���� �б� : fread()
// size_t fread(void *buffer, size_t size(sizeof(int)), size_t count, FILE *fp)

// ���� ���� ���� : fwrite()
// size_t fwrite(void *buffer, size_t size(sizeof(int)), size_t count, FILE *fp)

// ���� ���� �б� ���� ���� �ڵ� 1
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
		fprintf(stderr, "������ �� �� ����");
		return 1;
	}

	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);

	for (i = 0; i < SIZE; i++)
		buffer[i] = 0;

	fp = fopen("binary.bin", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "������ �� �� ����");
		return 1;
	}

	fread(buffer, sizeof(int), SIZE, fp);
	for (i = 0; i < SIZE; i++)
		printf("%d ", buffer[i]);

	fclose(fp);
	return 0;
}
*/

// ���� ���� �б� ���� ���� �ڵ� 2
/*
#include <stdio.h>
int main()
{
	FILE* src, * dst;
	char filename[100];
	char buffer[1024];
	int r_count;

	printf("�̹��� ���� �̸� : ");
	scanf("%s", filename);

	src = fopen(filename, "rb");
	dst = fopen("copy.jpg", "wb");
	if (src == NULL || dst == NULL)
	{
		fprintf(stderr, "���� ���� ����\n");
		return 1;
	}

	while ((r_count = fread(buffer, 1, sizeof(buffer), src)) > 0)
	{
		int w_count = fwrite(buffer, 1, r_count, dst);
		if (w_count < 0)
		{
			fprintf(stderr, "���� ���� ����\n");
			return 1;
		}
		if (w_count < r_count)
		{
			fprintf(stderr, "�̵�� ���� ����\n");
			return 1;
		}
	}
	printf("copy.jpg�� �̹��� ���� �����\n");
	fclose(src);
	fclose(dst);
	return 0;
}
*/

// ������ ���� ����

// ���� ���� : ������ ��� ��ġ������ ���� �б�
// ���� ��ġ ǥ���ڸ� ������ �̵���Ű�� ���� ���� ����
// ���� �б� ��� ���, ���� ��ġ ǥ���ڴ� 0
// ���� ���� ��� ���, ���� ��ġ ǥ���ڴ� ������ ���� ����Ŵ(EOF)

// ������ ���� ���� �Լ� : fseek()
// int fseek(FILE *fp, long offset, SEEK_SET(0)) : ������ ����
// int fseek(FILE *fp, long offset, SEEK_CUR(1)) : ���� ��ġ
// int fseek(FILE *fp, long offset, SEEK_END(2)) : ������ ��

// fseek���� �ϳ� ����ϰ� ���� �� ���� ĭ ��ġ�� ��ġ �����ڰ� �̵���

// ���Ͽ��� �ܾ� ã�� ���� �ڵ�
/*
#include <stdio.h>
int main()
{
	FILE* fp = NULL;
	char fname[100], word[100], buffer[1000];
	int count = 0;

	printf("���� �̸� : ");
	scanf("%s", fname);
	printf("Ž���� �ܾ� : ");
	scanf("%s", word);

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
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