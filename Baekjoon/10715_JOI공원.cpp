#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<bool> check;
vector<vector<pair<int, int>>> info;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m, x;
	cin >> n >> m >> x;
	check.assign(n + 1, false);
	info.assign(n + 1, vector<pair<int, int>>());

	long long sum = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		info[a].push_back({b,c});
		info[b].push_back({a,c});
		sum += c;
	}

	priority_queue<pair<long long, int>> pq;
	long long ans = LLONG_MAX;
	pq.push({0,1});
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (check[pos])
			continue;
		check[pos] = true;

		for (auto a : info[pos]) {
			int next = a.first;
			int ncost = a.second;

			if (check[next])
				sum -= ncost;
			pq.push({-cost-ncost, next});
		}
		ans = min(ans, sum + cost*x);
	}

	cout << ans;

	return 0;
}