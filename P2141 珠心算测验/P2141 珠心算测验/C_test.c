#pragma warning(disable:4996)//��ֹ��ʾ������scanf_s����scanf
#pragma warning(disable:6031)//��ֹ��ʾscanf����ֵ�����Եı���

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int BubbleSort_array[], int BubbleSort_length)//ð�����򣬴�С��������
{
	int BubbleSort_i, BubbleSort_j, BubbleSort_temp, BubbleSort_flag = 1;//����һ����ʱ����temp���ڴ������ݽ��������е���ʱ���ݣ�����һ�����Ʊ���flag�����ж��Ƿ�������

	for (BubbleSort_i = 0; BubbleSort_i <= BubbleSort_length - 1; BubbleSort_i++)//������Ҫ����n-1�ֽ�����ÿ�����������ֻᱻ����ĩβ��n-1����ɺ���С���������ڿ�ͷ
	{
		if (BubbleSort_flag == 0)//�ж���һ���Ƿ������ݽ���
		{
			goto exit_all_loop;//����޽�����������ֱ���˳�����ѭ��
		}
		else {
			BubbleSort_flag = 0;//���Ʊ�־����

			for (BubbleSort_j = 0; BubbleSort_j < BubbleSort_length - 1 - BubbleSort_i; BubbleSort_j++)//ÿ����Ҫ�Ƚ�n-1-i�Σ���Ϊÿ�ֹ���ĩβ���ǰ�˳���źõģ���ĩβ����Ƚ�
			{
				if (BubbleSort_array[BubbleSort_j] > BubbleSort_array[BubbleSort_j + 1])
				{
					BubbleSort_flag++;//����������ݽ�������flag����1

					BubbleSort_temp = BubbleSort_array[BubbleSort_j + 1];//����temp������jλ�͵�j+1λ����ֵ
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
					goto skip_current_loop;//��Ŀֻ��һ����ʽ����
				}

			}
		}
	skip_current_loop:continue;
	}

	printf("%d", count);
	system("pause");
	return 0;
}