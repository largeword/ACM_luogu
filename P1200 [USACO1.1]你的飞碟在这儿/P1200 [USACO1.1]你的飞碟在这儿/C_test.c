#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int main()
{

	char a[7] = "", b[7] = "";//�����[6]��#1�ͻ�WA 
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