#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

/*int TypeOFInput(char array[])//�ж����������ʲô���ͣ�����rt sign*100+��βλ�ã�С��rt sign*100+С����λ�ã�����rt sign*100+б��λ�ã��ٷ���rt sign*100+���һλ����λ��
{
	int TypeOFInput_i, TypeOFInput_sign = 1, TypeOFInput_location;//����sign=1��С��sign=2������sign=3���ٷ���sign=4

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

int FindEnd(char array[])//�ҵ�����ĩβ����Ԫ��λ��
{
	int FindEnd_i;
	for (FindEnd_i = 0; FindEnd_i < 25; FindEnd_i++)
	{
		if (array[FindEnd_i] == '\0') return FindEnd_i - 1;
		else continue;
	}
}

void copy1(char input[], char output[], int begin_i, int end_i, int begin_o)//����һ��δ������������һ���������¼���������ݣ�����input\output��ʼԪ��λ�ú�input����Ԫ��λ��,����ͷ����Ϊ0������
{
	int copy_i, copy_j = end_i, copy_flag = 0;//����һ��flag�ж�0�Ƿ���ĩβ
	
	for (copy_i = begin_o; copy_i <= 25; copy_i++)
	{
		while (copy_j >= begin_i)//�Ӻ���ǰ����input
		{
			if (input[copy_j] == '0' && copy_flag == 0) copy_j--;//���Ӻ���ǰ����ʱ���������0������
			else {
				output[copy_i] = input[copy_j];//output��ͷ��һ�ַ�����inputĩβ��һ����0�ַ�
				copy_j--;
				copy_flag = 1;
				goto exit_j;
			}
		}
	exit_j:continue;
	}
	if (output[0] == '\0')
	{
		output[0] = '0';//���inputֻ��0��outputҲΪ0
		output[1] = '\0';
	}
}

void copy2(char input[], char output[], int begin_i, int end_i, int begin_o)//����һ��δ������������һ���������¼���������ݣ�����input\output��ʼԪ��λ�ú�input����Ԫ��λ��,����ͷ��Ϊ0������
{
	int copy_i, copy_j = end_i;

	for (copy_i = begin_o; copy_i <= 25; copy_i++)
	{
		while (copy_j >= begin_i)//�Ӻ���ǰ����input
		{
			output[copy_i] = input[copy_j];//output��ͷ��һ�ַ�����inputĩβ��һ����0�ַ�
			copy_j--;
			goto exit_j;
		}
	exit_j:continue;
	}
}

void reverse(char input[], char output[], int param)//������������鼰�������͵�ת����
{
	int reverse_sign = param / 100, reverse_location = param % 100, reverse_i, reverse_j = 4, reverse_end, reverse_end2;

	if (reverse_sign == 1)//�ж��Ƿ�Ϊ����
	{
		copy1(input, output, 0, reverse_location, 0);
	}
	else if (reverse_sign == 4)//�ж��Ƿ�Ϊ�ٷ���
	{
		copy1(input, output, 0, reverse_location, 0);
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '%';//ĩβ��Ӱٷֺ�
	}
	else if (reverse_sign == 2)//�ж��Ƿ�ΪС��
	{
		
		copy1(input, output, 0, reverse_location - 1, 0);//��תС����ǰ����
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '.';//���С����
		reverse_end2 = FindEnd(input);//�ҵ����һλ���ֵ�λ��
		copy2(input, output, reverse_location + 1, reverse_end2, reverse_end + 2);//С����֮��������Դ�0��ʼ
		reverse_end2 = FindEnd(output);
		for (reverse_i = reverse_end2; reverse_i > reverse_end + 2; reverse_i--)//С���������ֲ�����0��β
		{
			if (output[reverse_i] == '0') output[reverse_i] = '\0';
			else break;
		}
	}
	else if (reverse_sign == 3)//�ж��Ƿ�Ϊ����
	{
		
		copy1(input, output, 0, reverse_location - 1, 0);//��ת�ֺ�ǰ����
		reverse_end = FindEnd(output);
		output[reverse_end + 1] = '/';//��ӷֺ�
		reverse_end2 = FindEnd(input);//�ҵ����һλ���ֵ�λ��
		copy1(input, output, reverse_location + 1, reverse_end2, reverse_end + 2);//��ת�ֺź�����
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

int TypeOFInput(char array[])//�����Ƿ���./%�ȷ��ţ������򷵻� �÷��ŵ�λ��*100+ĩβλ�ã���û���򷵻� 0*100+ĩβλ��
{
	int i, location = 0, end;

	for (i = 0; i < 25 && array[i] != '\0'; i++)
	{
		if (array[i] >= 37 && array[i] <= 47)//ascii���Ƿ��ڡ���%֮�䣬����Ƿ���ڷ���
		{
			location = i;//�����򷵻ط���λ��
			continue;
		}
		else continue;
	}
	end = i - 1;

	return location * 100 + end;
}

int FindEnd(char array[])//�ҵ�����ĩβ����Ԫ��λ��
{
	int FindEnd_i;
	for (FindEnd_i = 0; FindEnd_i < 25; FindEnd_i++)
	{
		if (array[FindEnd_i] == '\0') return FindEnd_i - 1;
		else continue;
	}

	return -1;//���Ҳ������򷵻�-1
}

void copy(char input[], int input_begin, int input_end, char output[], int output_begin)
{
	int copy_i, copy_j = input_end, copy_flag = 0;
	
	if (input_begin > input_end) return;
	else {
		for (copy_i = output_begin; copy_i <= 25; copy_i++)
		{
			while (copy_j >= input_begin)//�Ӻ���ǰ����input
			{
				if (input[copy_j] == '0' && copy_flag == 0) copy_j--;//���Ӻ���ǰ����ʱ���������0������
				else {
					output[copy_i] = input[copy_j];//output��ͷ��һ�ַ�����inputĩβ��һ����0�ַ�
					copy_j--;
					copy_flag = 1;
					goto exit_j;
				}
			}
		exit_j:continue;
		}

		if (output[output_begin] == '\0')
		{
			output[output_begin] = '0';//���inputֻ��0��outputҲΪ0
			output[output_begin + 1] = '\0';
		}
	}
}

void reverse(char input[], char output[], int param)
{
	int sign_location = param / 100, end_location = param % 100, reverse_end;//ԭ���з���λ����βλ����ʱ�����������н�βλ��

	if (sign_location == 0) copy(input, 0, end_location, output, 0);//�����������ʱ��ֱ�ӷ�ת������λ
	else {
		copy(input, 0, sign_location - 1, output, 0);//������ʱ���ȷ�ת����ǰ�����λ
		reverse_end = FindEnd(output);//�ҵ��������ĩβλ��
		output[reverse_end + 1] = input[sign_location];//��ԭ���еķ��Ÿ��Ƶ���������
		copy(input, sign_location + 1, end_location, output, reverse_end + 2);//��ת���ź����λ

		reverse_end = FindEnd(output);
		while (1) {
			if (output[reverse_end] == '0' && output[reverse_end - 1] != '.')//����Ƿ�Ϊ0.0״̬
			{
				output[reverse_end] = '\0';//������ǣ���ͨ��ѭ��ȥ��������0
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