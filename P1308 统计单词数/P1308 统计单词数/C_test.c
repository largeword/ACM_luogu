#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(const char *input, const char *target, int *result)//���������������ӵ����飨���Ϊ�ַ�������Ҫ���ҵĵ���ÿ����ĸ��ɵ����飬������飨δ�ҵ�Ϊ-1���ҵ�Ϊ�����͵�һ��λ�ã�
{
	char search_word[11] = { '\0' }, search_temp;//����ʱ���鴢����������еĵ���
	int search_i, search_count = 0, search_location1 = -1, search_location2 = -1;//��¼ƥ�����count����¼ʵʱλ��location1����¼��һ��ƥ��λ��location2

	while (*input)
	{
		search_i = 0;
		
		while ((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z'))//�ж�input��ǰ�Ƿ�Ϊ��ĸ
		{
			search_temp = *input;//��ʱ����*input����ĸ
			if (search_temp > 'Z') search_temp -= 32;//����Сд��ĸ��Ϊ��д
			search_word[search_i] = search_temp;
			
			input++;//�ƶ�����һλ
			search_i++;
		}
		search_word[search_i] = '\0';//��ȡ���ĵ���ĩβ����\0
		input++;//input�����ո�
		search_location1++;//��ǰλ�ú���һλ

		if (strcmp(search_word, target) == 0)//�ж�ȡ���ĵ����Ƿ�ƥ��
		{
			search_count++;//ƥ�������1
			if (search_location2 == -1) search_location2 = search_location1;//�ж��Ƿ��ǵ�һ��ƥ�䣬��������¼��ǰλ��
		}
	}

	result[0] = search_count;
	result[1] = search_location2;
}

int main()
{
	char word[11] = { '\0' }, input[1000001] = { '\0' };
	int i, result[2];

	scanf("%s", word);
	getchar();//ȥ��������word֮��Ļس�
	fgets(input,1000000,stdin);

	for (i = 0; word[i] != '\0'; i++)//����Сд��ĸ��Ϊ��д
	{
		if (word[i] > 'Z') word[i] -= 32;
	}

	search(input, word, result);
	
	if (result[0] == 0) printf("%d\n", result[1]);//δ�ҵ��򷵻�-1
	else { printf("%d %d\n", result[0], result[1]); }//�ҵ��򷵻ش����͵�һ��λ��

	system("pause");
	return 0;
}