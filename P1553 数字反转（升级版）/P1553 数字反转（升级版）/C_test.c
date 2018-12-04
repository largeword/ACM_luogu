#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int TypeOFInput(char array[])//判断输入的数是什么类型，整数rt sign*100+结尾位置，小数rt sign*100+小数点位置，分数rt sign*100+斜杠位置，百分数rt sign*100+最后一位数字位置
{
	int TypeOFInput_i, TypeOFInput_sign = 1, TypeOFInput_location;//整数sign=1，小数sign=2，分数sign=3，百分数sign=4

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

void copy(char input[], char output[], int begin, int end)//传入一个未经处理的数组和一个空数组记录处理后的内容，传入开始元素位置和结束元素位置
{
	int copy_i, copy_j = end;
	
	for (copy_i = begin; copy_i <= end; copy_i++)
	{
		while (copy_j >= begin)//从后往前遍历input
		{
			if (input[copy_j] == '0') copy_j--;//当从后往前遍历时，如果遇到0则跳过
			else {
				output[copy_i] = input[copy_j];//output开头第一字符等于input末尾第一个非0字符
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