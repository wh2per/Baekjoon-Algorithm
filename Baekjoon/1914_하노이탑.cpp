#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(n - 1, from, to, by);		// n-1개 원판을 1에서 3을 이용하여 2로 옮긴다
	printf("%d %d\n", from, to);
	hanoi(n - 1, by, from, to);		// n-1개 원판을 2에서 1을 이용하여 3으로 옮긴다.
}

int bj_1914() {
	int i, j, tmp;
	char ctmp;
	int N, cnt=0;
	char data[50] = {'\0',};

	scanf("%d", &N);
	data[0] = '1';
	for (i = 1; i <= N; i++)
	{
		tmp = 0;
		for (j = cnt; j >= 0; j--)
		{
			tmp += (data[j] - '0') * 2;
			data[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		if (tmp > 0)
		{
			ctmp = tmp + '0';
			cnt++;
			for (j = cnt; j >= 1; j--)
			{
				data[j] = data[j - 1];
			}
			data[0] = ctmp;
		}
	}
	data[cnt]--;
	printf("%s\n", data);
	if (N <= 20)
		hanoi(N,1, 2, 3);
	return 0;
}