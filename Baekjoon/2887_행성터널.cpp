#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


// 프림 

vector<bool> visited;
vector<vector<int>> pos;
vector<vector<pair<int, int>>> info;

bool cmp_dist1(vector<int> d1, vector<int> d2) {
if (d1[1] < d2[1])
return true;
else
return false;
}

bool cmp_dist2(vector<int> d1, vector<int> d2) {
if (d1[2] < d2[2])
return true;
else
return false;
}

bool cmp_dist3(vector<int> d1, vector<int> d2) {
if (d1[3] < d2[3])
return true;
else
return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	visited.assign(n + 1, false);
	pos.assign(n, vector<int>());
	info.assign(n + 1, vector<pair<int, int>>());


	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		pos[i].push_back(i+1);
		pos[i].push_back(x);
		pos[i].push_back(y);
		pos[i].push_back(z);
	}

	sort(pos.begin(), pos.end(), cmp_dist1);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i-1][k] - pos[i][k]));
		info[pos[i-1][0]].push_back({pos[i][0],cost});
		info[pos[i][0]].push_back({pos[i-1][0],cost});
	}

	sort(pos.begin(), pos.end(), cmp_dist2);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i - 1][k] - pos[i][k]));
		info[pos[i-1][0]].push_back({pos[i][0],cost});
		info[pos[i][0]].push_back({pos[i-1][0],cost});
	}

	sort(pos.begin(), pos.end(), cmp_dist3);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i - 1][k] - pos[i][k]));
		info[pos[i-1][0]].push_back({pos[i][0],cost});
		info[pos[i][0]].push_back({pos[i-1][0],cost});
	}

	int ans = 0;
	priority_queue<pair<int, int>> pq;
	
	for (int i = 0; i < info[1].size(); ++i)
		pq.push({ -info[1][i].second, info[1][i].first });

	visited[1] = true;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;

		pq.pop();
		
		if (visited[curr])
			continue;
		visited[curr] = true;
		ans -= cost;

		for (int i = 0; i < info[curr].size(); ++i)
			pq.push({ -info[curr][i].second,info[curr][i].first });
	}

	cout << ans;
	return 0;
}


// 크루스칼

struct node {
	int x;
	int y;
	int cost;
};

vector<int> v;
vector<node> ci;
vector<vector<int>> pos;

bool cmp_cost(node c1, node c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

bool cmp_dist1(vector<int> d1, vector<int> d2) {
	if (d1[1] < d2[1])
		return true;
	else
		return false;
}

bool cmp_dist2(vector<int> d1, vector<int> d2) {
	if (d1[2] < d2[2])
		return true;
	else
		return false;
}

bool cmp_dist3(vector<int> d1, vector<int> d2) {
	if (d1[3] < d2[3])
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	pos.assign(n, vector<int>());
	v.assign(n + 1, 0);
	ci.assign(n + 1, node());

	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		pos[i].push_back(i+1);
		pos[i].push_back(x);
		pos[i].push_back(y);
		pos[i].push_back(z);
		v[i+1] = i+1;
	}
	
	sort(pos.begin(), pos.end(), cmp_dist1);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i-1][k] - pos[i][k]));
		ci.push_back({ pos[i-1][0],pos[i][0],cost });
	}

	sort(pos.begin(), pos.end(), cmp_dist2);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i - 1][k] - pos[i][k]));
		ci.push_back({ pos[i - 1][0],pos[i][0],cost });
	}

	sort(pos.begin(), pos.end(), cmp_dist3);
	for (int i = 1; i < n; ++i) {
		int cost = INT_MAX;
		for (int k = 1; k < 4; ++k)
			cost = min(cost, abs(pos[i - 1][k] - pos[i][k]));
		ci.push_back({ pos[i - 1][0],pos[i][0],cost });
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

	cout << ans;
	return 0;
}