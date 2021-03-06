#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

/*int TypeOFInput(char array[])//判断输入的数是什么类型，整数rt sign*100+结尾位置，小数rt sign*100+小数点位置，分数rt sign*100+斜杠位置，百分数rt sign*100+最后一位数字位置
{
	int TypeOFInput_i, TypeOFInput_sign = 1, TypeOFInput_location;//整数sign=1，小数sign=2，分数sign=3，百分数sign=4

	for (TypeOFInput_i = 0; TypeOFInput_i < 25 && array[TypeOFInput_i] != '\0'; TypeOFInput_i++)
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

int FindEnd(char array[])//找到数组末尾数字元素位置
{
	int FindEnd_i;
	for (FindEnd_i = 0; FindEnd_i < 25; FindEnd_i++)
	{
		if (array[FindEnd_i] == '\0') return FindEnd_i - 1;
		else continue;
	}
}

void copy1(char input[], char output[], int begin_i, int end_i, int begin_o)//传入一个未经处理的数组和一个空数组记录处理后的内容，传入input\output开始元素位置和input结束元素位置,处理开头不能为0的数字
{
	int copy_i, copy_j = end_i, copy_flag = 0;//定义一个flag判断0是否处于末尾
	
	for (copy_i = begin_o; copy_i <= 25; copy_i++)
	{
		while (copy_j >= begin_i)//从后往前遍历input
		{
			if (input[copy_j] == '0' && copy_flag == 0) copy_j--;//当从后往前遍历时，如果遇到0则跳过
			else {
				output[copy_i] = input[copy_j];//output开头第一字符等于input末尾第一个非0字符
				copy_j--;
				copy_flag = 1;
				goto exit_j;
			}
		}
	exit_j:continue;
	}
	if (output[0] == '\0')
	{
		output[0] = '0';//如果input只有0则output也为0
		output[1] = '\0';
	}
}

void copy2(char input[], char output[], int begin_i, int end_i, int begin_o)//传入一个未经处理的数组和一个空数组记录处理后的内容，传入input\output开始元素位置和input结束元素位置,处理开头能为0的数字
{
	int copy_i, copy_j = end_i;

	for (copy_i = begin_o; copy_i <= 25; copy_i++)
	{
		while (copy_j >= begin_i)//从后往前遍历input
		{
			output[copy_i] = input[copy_j];//output开头第一字符等于input末尾第一个非0字符
			copy_j--;
			goto exit_j;
		}
	exit_j:continue;
	}
}

void reverse(char input[], char output[], int param)//根据输入的数组及数组类型倒转数组
{
	int reverse_sign = param / 100, reverse_location = param % 100, reverse_i, reverse_j = 4, reverse_end, reverse_end2;

	if (reverse_sign == 1)//判断是否为整数
	{
		copy1(input, output, 0, reverse_location, 0);
	}
	else if (reverse_sign == 4)//判断是否为百分数
	{
		copy1(input, output, 0, reverse_location, 0);
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '%';//末尾添加百分号
	}
	else if (reverse_sign == 2)//判断是否为小数
	{
		
		copy1(input, output, 0, reverse_location - 1, 0);//倒转小数点前数字
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '.';//添加小数点
		reverse_end2 = FindEnd(input);//找到最后一位数字的位置
		copy2(input, output, reverse_location + 1, reverse_end2, reverse_end + 2);//小数点之后的数可以从0开始
		reverse_end2 = FindEnd(output);
		for (reverse_i = reverse_end2; reverse_i > reverse_end + 2; reverse_i--)//小数点后的数字不能以0结尾
		{
			if (output[reverse_i] == '0') output[reverse_i] = '\0';
			else break;
		}
	}
	else if (reverse_sign == 3)//判断是否为分数
	{
		
		copy1(input, output, 0, reverse_location - 1, 0);//倒转分号前数字
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '/';//添加分号
		reverse_end2 = FindEnd(input);//找到最后一位数字的位置
		copy1(input, output, reverse_location + 1, reverse_end2, reverse_end + 2);//倒转分号后数字
	}
}

int main()
{
	int type, i;
	char raw[25], ripe[25] = { '\0' };

	scanf("%s", &raw);

	type = TypeOFInput(raw);
	reverse(raw, ripe, type);

	//printf("%d\n", type);

	for (i = 0; i < 22 && ripe[i] != '\0' && ripe[i] != -52; i++)
	{
		printf("%c", ripe[i]);
	}

	system("pause");
	return 0;
}*/

int TypeOFInput(char array[])//查找是否有./%等符号，如有则返回 该符号的位置*100+末尾位置，如没有则返回 0*100+末尾位置
{
	int i, location = 0, end;

	for (i = 0; i < 25 && array[i] != '\0'; i++)
	{
		if (array[i] >= 37 && array[i] <= 47)//ascii码是否在。到%之间，检查是否存在符号
		{
			location = i;//如有则返回符号位置
			continue;
		}
		else continue;
	}
	end = i - 1;

	return location * 100 + end;
}

int FindEnd(char array[])//找到数组末尾数字元素位置
{
	int FindEnd_i;
	for (FindEnd_i = 0; FindEnd_i < 25; FindEnd_i++)
	{
		if (array[FindEnd_i] == '\0') return FindEnd_i - 1;
		else continue;
	}

	return -1;//若找不到，则返回-1
}

void copy(char input[], int input_begin, int input_end, char output[], int output_begin)
{
	int copy_i, copy_j = input_end, copy_flag = 0;
	
	if (input_begin > input_end) return;
	else {
		for (copy_i = output_begin; copy_i <= 25; copy_i++)
		{
			while (copy_j >= input_begin)//从后往前遍历input
			{
				if (input[copy_j] == '0' && copy_flag == 0) copy_j--;//当从后往前遍历时，如果遇到0则跳过
				else {
					output[copy_i] = input[copy_j];//output开头第一字符等于input末尾第一个非0字符
					copy_j--;
					copy_flag = 1;
					goto exit_j;
				}
			}
		exit_j:continue;
		}

		if (output[output_begin] == '\0')
		{
			output[output_begin] = '0';//如果input只有0则output也为0
			output[output_begin + 1] = '\0';
		}
	}
}

void reverse(char input[], char output[], int param)
{
	int sign_location = param / 100, end_location = param % 100, reverse_end;//原数列符号位，结尾位，临时变量储存数列结尾位置

	if (sign_location == 0) copy(input, 0, end_location, output, 0);//输入的是整数时，直接反转所有数位
	else {
		copy(input, 0, sign_location - 1, output, 0);//非整数时，先反转符号前面的数位
		reverse_end = FindEnd(output);//找到新数组的末尾位置
		output[reverse_end + 1] = input[sign_location];//把原数列的符号复制到新数列中
		copy(input, sign_location + 1, end_location, output, reverse_end + 2);//反转符号后的数位

		reverse_end = FindEnd(output);
		while (1) {
			if (output[reverse_end] == '0' && output[reverse_end - 1] != '.')//检查是否为0.0状态
			{
				output[reverse_end] = '\0';//如果不是，则通过循环去除最后面的0
				reverse_end--;
			}
			else break;
		}
	}
}

int main()
{
	int type, i;
	char raw[25], ripe[25] = { '\0' };

	scanf("%s", &raw);

	type = TypeOFInput(raw);
	reverse(raw, ripe, type);

	for (i = 0; i < 22 && ripe[i] != '\0' && ripe[i] != -52; i++)
	{
		printf("%c", ripe[i]);
	}

	system("pause");
	return 0;
}