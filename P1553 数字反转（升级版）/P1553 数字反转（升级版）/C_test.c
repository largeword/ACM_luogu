#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

int TypeOFInput(char array[])//�ж����������ʲô���ͣ�����rt sign*100+��βλ�ã�С��rt sign*100+С����λ�ã�����rt sign*100+б��λ�ã��ٷ���rt sign*100+��βλ��
{
	int i, sign = 1, location;//����sign=1��С��sign=2������sign=3���ٷ���sign=4

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
			location = i;
		}
		else continue;
	}
	if (sign == 1) location = i - 1;

	return sign * 100 + location;
}

/*void reverse(char array[], int sign)
{

}
*/
int main()
{
	char array[22]= { '1', '2', '3', '5', '4' };
	int a;

	a = TypeOFInput(array);

	printf("%d", a);

	system("pause");
	return 0;
}