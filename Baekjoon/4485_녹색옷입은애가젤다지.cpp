#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int dx[] = { 0, -1 , 0 ,1 };
const int dy[] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test = 0;
	while (1) {
		int n;
		cin >> n;

		if (n == 0)
			break;
		++test;

		vector<vector<int>> arr(n, vector<int>(n, 0));
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];

		priority_queue < pair<int, pair<int, int>>> pq;
		dist[0][0] = arr[0][0];
		visited[0][0] = true;
		pq.push({ -arr[0][0], {0,0} });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();

			if (y == n - 1 && x == n - 1)
				break;

			for (int k = 0; k < 4; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >=n || visited[ny][nx])
					continue;

				if (dist[ny][nx] > dist[y][x] + arr[ny][nx]) {
					dist[ny][nx] = dist[y][x] + arr[ny][nx];
					visited[ny][nx] = true;
					pq.push({ -dist[ny][nx], {ny, nx} });
				}
			}
		}

		cout << "Problem " << test << ": " << dist[n - 1][n - 1] << "\n";
	}
	return 0;
}