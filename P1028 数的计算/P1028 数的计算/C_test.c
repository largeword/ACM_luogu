#pragma warning(disable:4996)//禁止显示建议用scanf_s代替scanf
#pragma warning(disable:6031)//禁止显示scanf返回值被忽略的报错

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, cnt = 1, i, f[1010];
	
	f[0] = f[1] = 1;
	scanf("%d", &n);
	
	for (i = 2; i <= n; i++) 
	{
		if (i % 2 == 0)
		{
			f[i] = f[i - 1] + f[i / 2];
		}
		else {
			f[i] = f[i - 1];
		}
	}
	
	printf("%d\n", f[n]);

	system("pause");
	return 0;
}