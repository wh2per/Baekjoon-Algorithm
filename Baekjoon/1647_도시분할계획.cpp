#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
};

bool cmp_node(node n1, node n2) {
	if (n1.cost < n2.cost)
		return true;
	else
		return false;
}

vector<int> v;
vector<node> ci;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.assign(n + 1, 0);
	ci.clear();

	for (int i = 0; i <= n; ++i)
		v[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		ci.push_back({a,b,c});
	}
	sort(ci.begin(), ci.end(), cmp_node);

	int ans = 0;
	int cnt = 0;
	int p1, p2;
	for (int i = 0; i < ci.size(); ++i) {
		p1 = find(ci[i].x);
		p2 = find(ci[i].y);

		if (p1 == p2)
			continue;

		ans += ci[i].cost;
		v[p2] = p1;
		++cnt;
		if (cnt == n - 2)
			break;
	}

	cout << ans;

	return 0;
}