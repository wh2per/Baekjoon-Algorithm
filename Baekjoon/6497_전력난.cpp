#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct node {
	int x, y, cost;
};

vector<node> ci;
vector<int> v;

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

	while (1) {
		int n, m;
		cin >> m >> n;

		if (n == 0 && m == 0)
			break;

		v.assign(m, 0);
		for (int i = 0; i < m; ++i)
			v[i] = i;
		ci.clear();

		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			ci.push_back({ x,y,z });
			sum += z;
		}
		sort(ci.begin(), ci.end(), cmp_node);

		long long ans = 0;
		for (int i = 0; i < ci.size(); ++i) {
			int p1 = find(ci[i].x);
			int p2 = find(ci[i].y);

			if (p1 == p2)
				continue;

			ans += ci[i].cost;
			v[p2] = p1;
		}

		cout << sum - ans << "\n";
	}
	return 0;
}
