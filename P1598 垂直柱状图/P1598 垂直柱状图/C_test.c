#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

void scan(char input[], int count[])//ɨ�����鲢��¼��ĸ���ִ���
{
	int location, i;
	
	for (i = 0; i <= 100 && input[i] != '\0'; i++)//���������β'\0'���˳�
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			location = (char)(input[i] - 65);//��¼��ĸ��Ӧ��λ�ã�A��ĸ��ͳ��λ����count����ĵ�0λ
			count[location]++;//��Ӧλ������1
		}
		else continue;
	}
}

void print(int count[])//��ӡ��״ͼ
{
	int max = 0, n, i, j, k;
	
	for (i = 0; i <= 25; i++)
	{
		if (count[i] > max) max = count[i];//�ҵ��������Ĵ���
		else continue;
	}

	n = max;
	for (i = 1; i <= max; i++)//�����Ҫ��ӡmax��*��һ����Ҫ��ӡmax��
	{
		for (j = 0; j <= 25; j++)
		{
			if (count[j] == n)//������һ�����Ӵ���״ͼ�������������ƶ�����ÿ�����Ӷ�����������ʱ��ӡ*�����ܾʹ�ӡ�ո�
			{
				printf("*");
				if (j != 25) printf(" ");//���һ�����Ӻ���û�пո�ǰ�����ڵ������ÿո�ָ�
				count[j]--;
			}
			else {
				printf(" ");
				if (j != 25) printf(" ");
			}
		}

		printf("\n");
		n--;
	}

	for (k = 65; k <= 90; k++)//��ӡ��ײ�����ĸA-Z
	{
		printf("%c", (char)k);
		if (k != 90) printf(" ");//���һ����ĸ����û�пո�ǰ�����ڵ���ĸ�ÿո�ָ�
	}


}

int main()
{
	char input1[101] = { '\0' }, input2[101] = { '\0' }, input3[101] = { '\0' }, input4[101] = { '\0' };//ȫ����'\0'���
	int count[26] = { 0 };//ȫ����0���

	fgets(input1, 100, stdin);
	fgets(input2, 100, stdin);
	fgets(input3, 100, stdin);
	fgets(input4, 100, stdin);

	scan(input1, count);
	scan(input2, count);
	scan(input3, count);
	scan(input4, count);

	print(count);

	system("pause");
	return 0;
}