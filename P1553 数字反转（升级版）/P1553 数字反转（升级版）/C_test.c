#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int TypeOFInput(char array[])//判断输入的数是什么类型，整数rt sign*100+结尾位置，小数rt sign*100+小数点位置，分数rt sign*100+斜杠位置，百分数rt sign*100+最后一位数字位置
{
	int i, sign = 1, location;//整数sign=1，小数sign=2，分数sign=3，百分数sign=4

	for (i = 0; i < 22 && array[i] != '\0'; i++)
	{
		if (array[i] == '.')
		{
			sign = 2;
			location = i;
		}
		else if (array[i] == '/')
		{
			sign = 3;
			location = i;
		}
		else if (array[i] == '%')
		{
			sign = 4;
			location = i - 1;
		}
		else continue;
	}
	if (sign == 1) location = i - 1;

	return sign * 100 + location;
}

void reverse(char input[], char output[], int param)
{
	int sign, location, i, j;
	sign = param / 100; location = param % 100;

	if (sign == 1)
	{
		for (i = 0, j = 0; i < location + 1; i++)
		{
			if (input[location - j] == '0')
			{
				j++;
				continue;
			}
			else {
				output[i] = input[location - j - i];
			}
		}
	}
}

int main()
{
	char raw[22] = { '1','2','3','0','0' }, reverse1[22] = { '*' };
	int a;


	a = TypeOFInput(raw);

	reverse(raw, reverse1, a);

	printf("%d", a);
	for (a = 0; a < 22 && reverse1[a] != '\0' && reverse1[a] != -52; a++)
	{
		printf("%c", reverse1[a]);
	}

	system("pause");
	return 0;
}