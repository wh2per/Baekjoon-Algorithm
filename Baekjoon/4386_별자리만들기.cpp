#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

// 크루스칼

struct node {
	int x;
	int y;
	float cost;
};

vector<node> info;
vector<int> v;

bool cmp_cost(node c1, node c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int find(int n){
	if (v[n] == n)		// 같으면 리턴
		return n;
	v[n] = find(v[n]);	// 재귀 후 갱신
	return v[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<float,float>> dist(n + 1, pair<float, float>());
	v.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		float x, y;
		cin >> x >> y;

		v[i] = i;
		dist[i].first = x;
		dist[i].second = y;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) 
			info.push_back({i,j,sqrt(pow(dist[i].first - dist[j].first,2) + pow(dist[i].second - dist[j].second,2))});
	}

	sort(info.begin(), info.end(), cmp_cost);

	float ans = 0;
	int p1, p2;
	for (int i = 0; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;

		v[p1] = p2;
		ans += info[i].cost;
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}