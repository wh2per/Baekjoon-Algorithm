#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

const int dx[] = { 1,0,-1,0 };		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	vector<vector<int>> arr;

	string s;
	getline(cin, s);

	vector<int> line;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ')
			continue;
		else if (s[i] == ';') {
			arr.push_back(line);
			line.clear();
		}
		else {
			line.push_back(s[i] - '0');
		}
	}
	arr.push_back(line);

	int ans = 0;
	int n = arr.size();
	int m = arr[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 1) {
				for (int k = 0; k < 4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
						continue;
					if (arr[ny][nx] == 0)
						++ans;
				}
			}
		}
	}

	cout << ans;

	return 0;
}