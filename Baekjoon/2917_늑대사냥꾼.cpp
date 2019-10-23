#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

struct node {
	int y;
	int x;
	int dist;
	int ans;
};

vector<vector<char>> arr;
vector<vector<int>> dist;
vector<vector<bool>> check;

int starty;
int startx;
int endy;
int endx;
queue<pair<int, int>> tree;

int ans;

struct cmp_node {
	bool operator()(node n1, node n2) {
		if (n1.dist < n2.dist)
			return true;
		else
			return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	arr.assign(n, vector<char>(m, '.'));
	dist.assign(n, vector<int>(m, INT_MAX));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'V') {
				starty = i;
				startx = j;
			}
			else if (arr[i][j] == 'J') {
				endy = i;
				endx = j;
			}
			else if (arr[i][j] == '+') {
				tree.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!tree.empty()) {			// 나무까지의 거리 저장
		int y = tree.front().first;
		int x = tree.front().second;
		tree.pop();

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == '+')
				continue;

			if (dist[ny][nx] > dist[y][x] + 1) {
				dist[ny][nx] = dist[y][x] + 1;
				tree.push({ ny,nx });
			}
		}
	}

	priority_queue<node, vector<node>, cmp_node> pq;
	pq.push({ starty,startx,0,dist[starty][startx] });
	check[starty][startx] = true;

	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int ans = pq.top().ans;
		pq.pop();

		if (y == endy && x == endx) {
			cout << ans;
			return 0;
		}

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[ny][nx])
				continue;
			
			pq.push({ ny,nx,dist[ny][nx],min(ans,dist[ny][nx])});
			check[ny][nx] = true;
		}
	}
	return 0;
}
