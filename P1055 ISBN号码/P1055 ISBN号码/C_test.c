#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[14], mod[12] = "0123456789X"; //先将mod11后的十一个字符存入数组
	gets(a); //输入字符串（gets功能为读入一行，并将换行符转换为字符串结束符）

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

/*
#pragma warning(disable:4996);

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c, sum, i;
	char d, j;

	scanf("%d-%d-%d-%c", &a, &b, &c, &d);

	sum = a * 1 + (b / 100) * 2 + ((b / 10) % 10) * 3 + (b % 10) * 4 + (c / 10000) * 5 + ((c / 1000) % 10) * 6 + ((c / 100) % 10) * 7 + ((c / 10) % 10) * 8 + (c % 10) * 9;
	i = sum % 11;

	if (i == 10) j = 'X';
	else { j = (char)(i + 48); }

	if (d == j) printf("Right");
	else { printf("%d-%d-%d-%c", a, b, c, j); }

	system("pause");
	return 0;
}
*/