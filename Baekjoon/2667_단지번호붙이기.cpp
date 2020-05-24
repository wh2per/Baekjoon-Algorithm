#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char arr[26][26];
bool check[26][26];
queue<pair<int, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n;
vector<int> v;
int ans;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == '0' || check[i][j])
				continue;
			int cnt = 0;
			++ans;
			q.push({ i,j });
			check[i][j] = true;
			while (!q.empty()) {
				int cy = q.front().first;
				int cx = q.front().second;
				q.pop();
				++cnt;

				for (int k = 0; k < 4; ++k) {
					int ny = cy + dy[k];
					int nx = cx + dx[k];

					if (ny < 0 || ny >= n || nx < 0 || nx >= n || check[ny][nx] || arr[ny][nx] == '0')
						continue;
					q.push({ ny,nx });
					check[ny][nx] = true;
				}
			}
			v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());
	cout << ans << '\n';
	for (auto a : v)
		cout << a << '\n';
	return 0;
}