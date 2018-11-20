#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int main()
{

	char a[7] = "", b[7] = "";//如果是[6]，#1就会WA 
	scanf("%[A-Z]\n%[A-Z]", &a, &b);
	int c = 1, d = 1, i = 0;

	while (a[i] != '\0')
	{
		c = c * (a[i] - 'A' + 1);
		i++;
	}
	c = c % 47;
	i = 0;

	while (b[i] != '\0')
	{
		d = d * (b[i] - 'A' + 1);
		i++;
	}
	d = d % 47;

	if (c == d) printf("GO");
	else printf("STAY");

	system("pause");
	return 0;
}