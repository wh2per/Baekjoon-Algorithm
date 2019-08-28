#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 크루스칼 

struct node {
	int x;
	int y;
	int cost;
};

vector<node> info;
vector<int> v;

int find(int n)
{
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

bool cmp_cost(node c1, node c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t) {
		int n, e;
		cin >> n >> e;

		v.assign(n+1, 0);
		for (int i = 1; i <= n; ++i)
			v[i] = i;

		vector<node> ci;
		for (int i = 0; i < e; ++i) {
			int x, y;
			cin >> x >> y;

			ci.push_back({ x,y,1 });
		}
		sort(ci.begin(), ci.end(), cmp_cost);
		
		int ans = 0;
		int p1, p2;
		for (int i = 0; i < ci.size(); ++i) {
			p1 = find(ci[i].x);
			p2 = find(ci[i].y);

			if (p1 == p2)
				continue;

			v[p1] = p2;
			ans += ci[i].cost;
		}

		cout << ans<<"\n";
	}
	return 0;
}


// 프림 알고리즘

vector<vector<pair<int, int>>> info;
vector<bool> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t) {
		int n, e;
		cin >> n >> e;

		info.assign(n + 1, vector<pair<int, int>>());
		v.assign(n + 1, false);

		for (int i = 0; i < e; ++i) {
			int x, y;
			cin >> x >> y;

			info[y].push_back({ x,1 });
			info[x].push_back({ y,1 });
		}

		int ans = 0;
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < info[1].size(); ++i)
			pq.push({ -info[1][i].second, info[1][i].first });

		v[1] = true;
		while (!pq.empty()) {
			int pos = pq.top().second;
			int cost = -pq.top().first;

			pq.pop();

			if (v[pos])
				continue;
			v[pos] = true;
			ans += cost;

			for (int i = 0; i < info[pos].size(); ++i)
				pq.push({ -info[pos][i].second,info[pos][i].first });
		}
		cout << ans << " \n";
	}
	return 0;
}
