#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[14], mod[12] = "0123456789X"; //�Ƚ�mod11���ʮһ���ַ���������
	gets(a); //�����ַ�����gets����Ϊ����һ�У��������з�ת��Ϊ�ַ�����������

	int i, j = 1, t = 0;

	for (i = 0; i < 12; i++) 
	{
		if (a[i] == '-') continue; //�ַ���Ϊ�ָ�����-��ʱ�����˴�ѭ��������һ��ѭ��
		t += (a[i] - '0')*j++; //t���� ��j��  ����  * j �ĺ�
	}

	if (mod[t % 11] == a[12]) printf("Right");
	else {
		a[12] = mod[t % 11]; //��ʶ�����������ȷ��ʶ���룬Ȼ�����
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