#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
using namespace std;

struct node {
	int x, y, cost;
};

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0, };

vector<node> ci;
vector<int> v;
vector<vector<char>> arr;
vector<vector<bool>> check;
vector<pair<int, int>> sp;
map<pair<int, int>, int> match;

bool cmp_node(node n1, node n2) {
	if (n1.cost < n2.cost)
		return true;
	else
		return false;
}

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt","r",stdin);

	int n, m;
	cin >> n >> m;

	arr.assign(n, vector<char>(n));

	int num = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S' || arr[i][j] == 'K') {
				arr[i][j] = 'K';
				match.insert({ { i,j }, num++ });
				sp.push_back({ i,j });
			}
		}
	}

	v.assign(num, 0);
	for (int i = 0; i < num; ++i)
		v[i] = i;

	int ans = 0;

	for (int i = 0; i < sp.size() - 1; ++i) {
		int starty = sp[i].first;
		int startx = sp[i].second;

		check.assign(n, vector<bool>(n, false));
		queue<pair<int, pair<int, int>>> q;
		q.push({ 0,{ starty,startx } });
		check[starty][startx] = true;
		arr[starty][startx] = 'S';
		while (!q.empty()) {
			int cost = q.front().first;
			int cy = q.front().second.first;
			int cx = q.front().second.second;
			q.pop();

			if (arr[cy][cx] == 'K')
				ci.push_back({ match[{starty, startx}], match[{cy, cx}], cost });

			for (int d = 0; d < 4; ++d) {
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == '1' || check[ny][nx])
					continue;
				check[ny][nx] = true;
				q.push({ cost + 1,{ ny,nx } });
			}
		}
		arr[starty][startx] = 'K';
	}
	sort(ci.begin(), ci.end(), cmp_node);

	int cnt = 0;
	for (int i = 0; i < ci.size(); ++i) {
		int p1 = find(ci[i].x);
		int p2 = find(ci[i].y);

		if (p1 == p2)
			continue;

		ans += ci[i].cost;
		v[p2] = p1;
		++cnt;
	}
	if (cnt == m)
		cout << ans;
	else
		cout << -1;
	return 0;
}