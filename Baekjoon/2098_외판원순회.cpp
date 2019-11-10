#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int w[16][16];
int dp[16][1 << 16];
int n;

int tsp(int curr, int state) {
	if (state == (1 << n) - 1) {
		if (w[curr][0] == 0)
			return 987654321;
		else
			return w[curr][0];
	}

	int& ret = dp[curr][state];
	if (ret != 0)
		return ret;

	int m = INT_MAX-16000001;
	for (int i = 1; i < n; ++i) {
		if (((state & (1 << i)) == 0) && (w[curr][i] != 0))			// 아직선택안한 도시 && 도시로 가는 비용이 0이 아닐때
			m = min(m, tsp(i, (state | (1 << i))) + w[curr][i]);
	}

	return ret = m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cin >> w[i][j];
	}

	cout << tsp(0,1);

	return 0;
}