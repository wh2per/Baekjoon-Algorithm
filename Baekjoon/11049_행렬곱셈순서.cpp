#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int bj_11049() {
	int d[501][501];		// d[i][j] = i번째 행렬부터 j번째 행렬까지 곱셈했을 때 연산 최소값
	int m[501][2];			// 행렬의 행과 열 정보
	memset(d, 0, sizeof(d));

	int n;
	scanf("%d",&n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d %d",&m[i][0], &m[i][1]);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			d[i][j] = INT_MAX;
			for (int k = i; k < j; k++)
				d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + m[i][0] * m[k][1] * m[j][1]);
		}
	}

	printf("%d",d[0][n-1]);
	return 0;
}