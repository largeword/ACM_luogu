#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int BubbleSort_array[], int BubbleSort_length)//冒泡排序，从小到大排列
{
	int BubbleSort_i, BubbleSort_j, BubbleSort_temp, BubbleSort_flag = 1;//定义一个临时变量temp用于储存数据交换过程中的临时数据，定义一个控制变量flag用于判断是否发生交换

	for (BubbleSort_i = 0; BubbleSort_i <= BubbleSort_length - 1; BubbleSort_i++)//至多需要进行n-1轮交换，每轮中最大的数字会被移至末尾，n-1轮完成后最小的数字留在开头
	{
		if (BubbleSort_flag == 0)//判断上一轮是否发生数据交换
		{
			goto exit_all_loop;//如果无交换发生，则直接退出所有循环
		}
		else {
			BubbleSort_flag = 0;//控制标志清零

			for (BubbleSort_j = 0; BubbleSort_j < BubbleSort_length - 1 - BubbleSort_i; BubbleSort_j++)//每轮需要比较n-1-i次，因为每轮过后末尾总是按顺序排好的，故末尾无须比较
			{
				if (BubbleSort_array[BubbleSort_j] > BubbleSort_array[BubbleSort_j + 1])
				{
					BubbleSort_flag++;//如果发生数据交换，则flag增加1

					BubbleSort_temp = BubbleSort_array[BubbleSort_j + 1];//借助temp交换第j位和第j+1位的数值
					BubbleSort_array[BubbleSort_j + 1] = BubbleSort_array[BubbleSort_j];
					BubbleSort_array[BubbleSort_j] = BubbleSort_temp;
				}
			}
		}
	}

	return;
exit_all_loop:return;
}

int main()
{
	int n, x, i, j, k, l, count = 0, arr[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		arr[i] = x;
	}

	BubbleSort(arr, n);

	for (j = 2; j < n; j++)
	{
		for (k = 0; k < j - 1; k++)
		{
			for (l = k + 1; l < j; l++)
			{
				if (arr[j] == arr[k] + arr[l] && arr[j] != arr[k] && arr[j] != arr[l] && arr[k] != arr[l])
				{
					count++;
					printf("%d=%d+%d\n", arr[j], arr[k], arr[l]);
					goto skip_current_loop;//题目只求一个等式即可
				}

			}
		}
	skip_current_loop:continue;
	}

	printf("%d", count);
	system("pause");
	return 0;
}