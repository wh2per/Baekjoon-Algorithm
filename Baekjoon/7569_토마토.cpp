#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[101][101][101];
int n, m, h;

int dx[] = { 1,0,0,0,0,-1 };
int dy[] = { 0,1,0,0,-1,0 };
int dz[] = { 0,0,1,-1,0,0 };

queue<pair<pair<int, int>, int>> q;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	int left = 0;

	for (int z = 0; z < h; ++z) {
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				cin >> arr[z][y][x];
				if (arr[z][y][x] == 0)
					++left;
				else if (arr[z][y][x] == 1)
					q.push({ {z,y},x });
			}
		}
	}

	int ans = 0;
	int cnt = 0;

	while (!q.empty()) {
		int size = q.size();
		bool flag = false;
		for (int i = 0; i < size; ++i) {
			int cz = q.front().first.first;
			int cy = q.front().first.second;
			int cx = q.front().second;

			q.pop();

			for (int k = 0; k < 6; ++k) {
				int nz = cz + dz[k];
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
					continue;
				if (arr[nz][ny][nx] != 0)
					continue;

				++cnt;
				q.push({ {nz,ny},nx });
				arr[nz][ny][nx] = 1;
				flag = true;
			}
		}
		if (flag)
			++ans;
	}

	if (left != cnt)
		cout << -1;
	else
		cout << ans;

	return 0;
}

