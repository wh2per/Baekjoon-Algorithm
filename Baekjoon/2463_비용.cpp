#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MOD = 1000000000;

struct node {
	int x, y, cost;
};

vector<int> parent;
vector<long long> vsize;
vector<node> info;

bool cmp_node(node n1, node n2) {
	if (n1.cost > n2.cost)
		return true;
	else
		return false;
}

int find(int n) {
	if (parent[n] == n)
		return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	parent[b] = a;
	vsize[a] += vsize[b];
	vsize[b] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long long total=0;
	cin >> n >> m;
	parent.assign(n + 1, 0);
	vsize.assign(n + 1, 1);
	info.clear();

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		info.push_back({x,y,w});
		total += w;
	}
	sort(info.begin(), info.end(), cmp_node);

	int p1, p2;
	long long ans = 0;
	for (int i = 0; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);
		int cost = info[i].cost;

		if (p1 != p2) {
			ans += (vsize[p1] * vsize[p2] * total) % MOD;
			ans %= MOD;
			merge(p1, p2);
		}
		total -= cost;
	}

	cout << ans;
	return 0;
}