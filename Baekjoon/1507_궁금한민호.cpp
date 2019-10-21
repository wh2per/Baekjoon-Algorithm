#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<vector<int>> arr(n,vector<int>(n,0));
	vector<vector<bool>> sub(n, vector<bool>(n, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; ++i) {		// 경유
		for (int j = 0; j < n; ++j) {	// 시작점
			for (int k = 0; k < n; ++k) { 	// 도착점
				if (i == j || j == k || i == k)
					continue;

				if (arr[j][k] == arr[j][i] + arr[i][k])		// 삭제할 간선
					sub[j][k] = true;
				else if (arr[j][k] > arr[j][i] + arr[i][k]) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!sub[i][j])
				ans += arr[i][j];
		}
	}

	cout << ans/2;
	return 0;
}