#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
};

vector<int> parent;
vector<vector<int>> info;
vector<node> ci;

bool cmp_node(node n1, node n2) {
	if (n1.cost < n2.cost)
		return true;
	else
		return false;
}

int find(int n) {
	if (parent[n] == n)
		return n;
	return parent[n] = find(parent[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	parent.assign(n + 1, 0);
	ci.clear();

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < k; ++i) {
		int num;
		cin >> num;
		parent[num] = 0;			// 발전소 등록
	}

	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		ci.push_back({ x,y,c });
	}
	sort(ci.begin(), ci.end(), cmp_node);

	long long ans = 0;
	int cnt = 0;
	int p1, p2;
	for (int i = 0; i < ci.size(); ++i) {
		p1 = find(ci[i].x);
		p2 = find(ci[i].y);

		if (p1 == p2)
			continue;

		parent[p2] = p1;
		ans += ci[i].cost;
	}

	cout << ans;

	return 0;
}