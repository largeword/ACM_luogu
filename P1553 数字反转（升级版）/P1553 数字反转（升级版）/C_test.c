#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int TypeOFInput(char array[])//�ж����������ʲô���ͣ�����rt sign*100+��βλ�ã�С��rt sign*100+С����λ�ã�����rt sign*100+б��λ�ã��ٷ���rt sign*100+���һλ����λ��
{
	int TypeOFInput_i, TypeOFInput_sign = 1, TypeOFInput_location;//����sign=1��С��sign=2������sign=3���ٷ���sign=4

	for (TypeOFInput_i = 0; TypeOFInput_i < 22 && array[TypeOFInput_i] != '\0'; TypeOFInput_i++)
	{
		if (array[TypeOFInput_i] == '.')
		{
			TypeOFInput_sign = 2;
			TypeOFInput_location = TypeOFInput_i;
		}
		else if (array[TypeOFInput_i] == '/')
		{
			TypeOFInput_sign = 3;
			TypeOFInput_location = TypeOFInput_i;
		}
		else if (array[TypeOFInput_i] == '%')
		{
			TypeOFInput_sign = 4;
			TypeOFInput_location = TypeOFInput_i - 1;
		}
		else continue;
	}
	if (TypeOFInput_sign == 1) TypeOFInput_location = TypeOFInput_i - 1;

	return TypeOFInput_sign * 100 + TypeOFInput_location;
}

int FindEnd(char array[])
{
	int FindEnd_i;
	for (FindEnd_i = 0; FindEnd_i < 22; FindEnd_i++)
	{
		if (array[FindEnd_i] == '\0') return FindEnd_i - 1;
		else continue;
	}
}

void copy(char input[], char output[], int begin, int end)//����һ��δ������������һ���������¼���������ݣ����뿪ʼԪ��λ�úͽ���Ԫ��λ��
{
	int copy_i, copy_j = end;
	
	for (copy_i = begin; copy_i <= end; copy_i++)
	{
		while (copy_j >= begin)//�Ӻ���ǰ����input
		{
			if (input[copy_j] == '0') copy_j--;//���Ӻ���ǰ����ʱ���������0������
			else {
				output[copy_i] = input[copy_j];//output��ͷ��һ�ַ�����inputĩβ��һ����0�ַ�
				copy_j--;
				goto exit_j;
			}
		}
	exit_j:continue;
	}
}

void reverse(char input[], char output[], int param)
{
	int reverse_sign = param / 100, reverse_location = param % 100, reverse_i, reverse_j=4;

	if (reverse_sign == 1)
	{
		copy(input, output, 0, reverse_location);
	}
	else if (reverse_sign == 4)
	{
		copy(input, output, 0, reverse_location);
		output[reverse_location + 1] = '%';
	}
	else if
}

int main()
{
	char raw[22] = { '1','2','3','0','0' }, reverse1[22] = { '\0' };
	int a;


	a = TypeOFInput(raw);

	reverse(raw, reverse1, a);

	printf("%d\n", a);
	for (a = 0; a < 22 && reverse1[a] != '\0' && reverse1[a] != -52; a++)
	{
		printf("%c", reverse1[a]);
	}

	system("pause");
	return 0;
}