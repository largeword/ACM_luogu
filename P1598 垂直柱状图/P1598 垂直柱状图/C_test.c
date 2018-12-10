#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

void scan(char input[], int count[])//扫描数组并记录字母出现次数
{
	int location, i;
	
	for (i = 0; i <= 100 && input[i] != '\0'; i++)//遇到数组结尾'\0'就退出
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			location = (char)(input[i] - 65);//记录字母对应的位置，A字母的统计位置在count数组的第0位
			count[location]++;//对应位置自增1
		}
		else continue;
	}
}

void print(int count[])//打印柱状图
{
	int max = 0, n, i, j, k;
	
	for (i = 0; i <= 25; i++)
	{
		if (count[i] > max) max = count[i];//找到出现最多的次数
		else continue;
	}

	n = max;
	for (i = 1; i <= max; i++)//最多需要打印max颗*，一共需要打印max行
	{
		for (j = 0; j <= 25; j++)
		{
			if (count[j] == n)//类似于一根杆子从柱状图的上面往下面移动，当每根柱子都能碰到杆子时打印*，不能就打印空格
			{
				printf("*");
				if (j != 25) printf(" ");//最后一个柱子后面没有空格，前面相邻的柱子用空格分隔
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

	for (k = 65; k <= 90; k++)//打印最底部的字母A-Z
	{
		printf("%c", (char)k);
		if (k != 90) printf(" ");//最后一个字母后面没有空格，前面相邻的字母用空格分隔
	}


}

int main()
{
	char input1[101] = { '\0' }, input2[101] = { '\0' }, input3[101] = { '\0' }, input4[101] = { '\0' };//全部用'\0'填充
	int count[26] = { 0 };//全部用0填充

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