#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int min = -32768 * 101;
using namespace std;

int sec_v[101];
int sec_d[101][51];		// DP[n][m] = n개의 원소들의 집합에서 m개의 구간으로 나누었을 때 합의 최대값
bool sec_check[101][101];

int recur_sec(int a, int b) {
	if (b == 0) 
		return 0;
	if (a <= 0) 
		return min;

	if (sec_check[a][b]) 
		return sec_d[a][b];

	sec_check[a][b] = true;

	int &ans = sec_d[a][b];
	ans = recur_sec(a - 1, b);
	
	int sum = 0;
	for (int k = a; k >= 1; --k) {
		sum += sec_v[k];
		int temp = recur_sec(k - 2, b - 1) + sum;
		if (ans < temp) 
			ans = temp;
	}

	return ans;
}

int bj_2228() {
	int n, m;
	scanf("%d %d",&n, &m);
	
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &sec_v[i]);

	printf("%d",recur_sec(n,m));
	return 0;
}