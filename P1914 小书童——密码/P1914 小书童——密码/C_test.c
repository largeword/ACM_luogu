#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j;
	char input[50] = { '\0' }, output[50] = { '\0' };

	scanf("%d", &n);
	scanf("%s", &input);

	for (i = 0; i <= 50 && input[i] != '\0'; i++)
	{
		j = input[i] + n;
		if (j > 122) j = j - 122 + 96;
		output[i] = j;
	}

	for (i = 0; i <= 50 && output[i] != '\0'; i++)
	{
		printf("%c", output[i]);
	}

	system("pause");
	return 0;
}