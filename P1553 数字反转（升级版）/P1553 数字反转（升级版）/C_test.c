#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int TypeOFInput(char array[])//判断输入的数是什么类型，整数rt结尾位置，小数rt小数点位置，分数rt斜杠位置，百分数rt0
{
	int i, sign = 0, lacate;//整数sign=0，小数sign=1，分数sign=2，百分数sign=3

	for (i = 0; i < 22 && array[i] != '/0'; i++)
	{
		if (array[i] == '.')
		{

		}
	}
}

int main()
{


	system("pause");
	return 0;
}