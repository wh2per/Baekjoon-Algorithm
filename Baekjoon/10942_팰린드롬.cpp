#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int palin_d[2000][2000];// d[i][j] = i~j까지가 팰린드롬이면 1 아니면 0
int palin_v[2000];

int palin_topdown(int s, int e) {
	if (s == e)			// 한자리 수 일때
		return 1;
	else if (s + 1 == e) {		// 두자리 수 일때
		if (palin_v[s] == palin_v[e])
			return 1;
		else
			return 0;
	}

	if (palin_d[s][e] != -1) 		// 초기값이 아니라면
		return palin_d[s][e];

	if (palin_v[s] != palin_v[e])	
		return palin_d[s][e] = 0;
	else
		return palin_d[s][e] = palin_topdown(s+1,e-1);
}

int bj_10942() {
	int n,m;
	scanf("%d", &n);

	memset(palin_d, -1, sizeof(palin_d));

	for (int i = 0; i < n; ++i)
		scanf("%d", &palin_v[i]);

	scanf("%d",&m);
	for (int i = 0; i < m; ++i) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", palin_topdown(s - 1, e - 1));
	}
	return 0;
}