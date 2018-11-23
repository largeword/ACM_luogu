#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[14], mod[12] = "0123456789X"; //先将mod11后的十一个字符存入数组
	gets(a); //输入字符串

	int i, j = 1, t = 0;

	for (i = 0; i < 12; i++) 
	{
		if (a[i] == '-') continue; //字符串为分隔符‘-’时跳过此次循环进入下一次循环
		t += (a[i] - '0')*j++; //t储存 第j个  数字  * j 的和
	}

	if (mod[t % 11] == a[12]) printf("Right");
	else {
		a[12] = mod[t % 11]; //若识别码错误，则赋正确的识别码，然后输出
		puts(a);
	}

	system("pause");
	return 0;
}