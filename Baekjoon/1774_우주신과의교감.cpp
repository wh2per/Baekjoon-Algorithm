#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// ũ�罺Į

struct node {
	int x;
	int y;
	double cost;
};

vector<int> v;
vector<node> ci;

bool cmp_cost(node c1, node c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int find(int n) {
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

void merge(int a, int b) {
	int num1, num2;
	num1 = find(a);
	num2 = find(b);
	if (num1 == num2)
		return;
	v[num1] = num2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;

	v.assign(n + 1, 0);
	vector<pair<double, double>> dist(n + 1, pair<float, float>());

	for (int i = 1; i <= n; ++i) {
		double x, y;
		cin >> x >> y;

		v[i] = i;
		dist[i].first = x;
		dist[i].second = y;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			ci.push_back({ i,j,sqrt(pow(dist[i].first - dist[j].first,2.0) + pow(dist[i].second - dist[j].second,2.0)) });
	}
	sort(ci.begin(), ci.end(), cmp_cost);

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;

		merge(x, y);
	}

	double ans = 0;
	int p1, p2;
	for(int i=0; i<ci.size(); ++i){
		p1 = find(ci[i].x);
		p2 = find(ci[i].y);

		if (p1 == p2)
			continue;

		v[p1] = p2;
		ans += ci[i].cost;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}