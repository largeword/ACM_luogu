#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[14], mod[12] = "0123456789X"; //�Ƚ�mod11���ʮһ���ַ���������
	gets(a); //�����ַ���

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