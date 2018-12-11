#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(const char *input, const char *target, int *result)//传入参数：输入句子的数组（拆分为字符），需要查找的单词每个字母组成的数组，结果数组（未找到为-1，找到为个数和第一次位置）
{
	char search_word[11] = { '\0' }, search_temp;//用临时数组储存句子数组中的单词
	int search_i, search_count = 0, search_location1 = -1, search_location2 = -1;//记录匹配次数count，记录实时位置location1，记录第一次匹配位置location2

	while (*input)
	{
		search_i = 0;
		
		while ((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z'))//判断input当前是否为字母
		{
			search_temp = *input;//临时储存*input的字母
			if (search_temp > 'Z') search_temp -= 32;//所有小写字母改为大写
			search_word[search_i] = search_temp;
			
			input++;//移动到下一位
			search_i++;
		}
		search_word[search_i] = '\0';//提取出的单词末尾加上\0
		input++;//input跳过空格
		search_location1++;//当前位置后移一位

		if (strcmp(search_word, target) == 0)//判断取出的单词是否匹配
		{
			search_count++;//匹配就增加1
			if (search_location2 == -1) search_location2 = search_location1;//判断是否是第一次匹配，如果是则记录当前位置
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
	getchar();//去除输入完word之后的回车
	fgets(input,1000000,stdin);

	for (i = 0; word[i] != '\0'; i++)//所有小写字母改为大写
	{
		if (word[i] > 'Z') word[i] -= 32;
	}

	search(input, word, result);
	
	if (result[0] == 0) printf("%d\n", result[1]);//未找到则返回-1
	else { printf("%d %d\n", result[0], result[1]); }//找到则返回次数和第一次位置

	system("pause");
	return 0;
}