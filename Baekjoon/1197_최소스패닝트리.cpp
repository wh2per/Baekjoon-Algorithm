#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 크루스칼 

typedef struct node {
	int x;
	int y;
	int cost;
};

vector<node> info;
int v[10001];

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

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		info.push_back({x,y,c});
	}
	sort(info.begin(), info.end(), cmp_cost);	// 비용이 적은 순으로 정렬	
	
	for (int i = 1; i <= n; ++i)		// 현재 자신의 수로 초기화
		v[i] = i;

	int p1, p2;
	long long ans = 0;
	for (int i = 0; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;

		v[p1] = p2;
		ans += info[i].cost;
	}

	cout << ans;
	return 0;
}


// 프림 알고리즘 

vector<vector<pair<int, int>>> info;
bool v[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e;
	cin >> n >> e;

	info.assign(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < e; ++i) {
		int x, y, c;
		cin >> x >> y >> c;

		info[y].push_back({ x,c });
		info[x].push_back({ y,c });
	}

	int p1, p2;
	long long ans = 0;
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < info[1].size(); ++i) 
		pq.push({-info[1][i].second, info[1][i].first});
	
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
			pq.push({-info[pos][i].second,info[pos][i].first});
	}
	cout << ans;
	return 0;
}

