#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// 크루스칼

struct node {
	int x, y, cost;
};

vector<int> v1;
vector<int> v2;
vector<node> ci1;
vector<node> ci2;

int find1(int n) {
	if (v1[n] == n)
		return n;
	return v1[n] = find1(v1[n]);
}

int find2(int n) {
	if (v2[n] == n)
		return n;
	return v2[n] = find2(v2[n]);
}

bool cmp_cost1(node c1, node c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

bool cmp_cost2(node c1, node c2) {
	if (c1.cost > c2.cost)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1) {
		int n, m, k;
		cin >> n >> m >> k;

		if (n == 0 && m == 0 && k == 0)
			break;
		v1.assign(n + 1, 0);
		v2.assign(n + 1, 0);
		ci1.clear();
		ci2.clear();

		for (int i = 1; i <= n; ++i) {
			v1[i] = i;
			v2[i] = i;
		}

		for (int i = 0; i < m; ++i) {
			char c;
			int x, y;
			cin >> c >> x >> y;
			if (c == 'B') {
				ci1.push_back({x,y,1});		// R에 가중치
				ci2.push_back({x,y,1});		// B에 가중치
			}
			else {
				ci1.push_back({ x,y,0 });
				ci2.push_back({ x,y,0 });
			}
		}

		sort(ci1.begin(), ci1.end(), cmp_cost1);
		sort(ci2.begin(), ci2.end(), cmp_cost2);

		int ans1 = 0;
		int p1, p2;
		for (int i = 0; i < ci1.size(); ++i) {
			p1 = find1(ci1[i].x);
			p2 = find1(ci1[i].y);

			if (p1 == p2)
				continue;

			v1[p1] = p2;
			ans1 += ci1[i].cost;
		}

		int ans2 = 0;
		for (int i = 0; i < ci2.size(); ++i) {
			p1 = find2(ci2[i].x);
			p2 = find2(ci2[i].y);

			if (p1 == p2)
				continue;

			v2[p1] = p2;
			ans2 += ci2[i].cost;
		}

		if (k >= ans1 && k <= ans2)
			cout << 1<<"\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}