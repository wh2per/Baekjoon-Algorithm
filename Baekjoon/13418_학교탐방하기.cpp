#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

struct node {
	int x, y, cost;
};

bool cmp_node1(node n1, node n2) {
	if (n1.cost > n2.cost)
		return true;
	else
		return false;
}

bool cmp_node2(node n1, node n2) {
	if (n1.cost < n2.cost)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt","r",stdin);

	int n, m;
	cin >> n >> m;

	v.assign(n + 1, 0);

	vector<node> info;
	for (int i = 0; i < m+1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info.push_back({a,b,c});
	}
	sort(info.begin(), info.end(),cmp_node1);

	for (int i = 1; i <= n; ++i)
		v[i] = i;

	int ans1 = 0;
	int p1, p2;
	for (int i = 0; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;

		v[p1] = p2;
		ans1 += info[i].cost;
	}

	sort(info.begin(), info.end(), cmp_node2);
	v[0] = 0;
	for (int i = 1; i <= n; ++i)
		v[i] = i;

	int ans2 = 0;
	for (int i = 0; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;

		v[p1] = p2;
		ans2 += info[i].cost;
	}
 	
	cout << (n-ans2)*(n-ans2) - (n - ans1) * (n - ans1);
	return 0;
}