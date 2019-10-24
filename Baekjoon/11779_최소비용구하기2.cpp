#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

vector<vector<pair<int, int>>> info;
vector<vector<int>> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n,m;
	cin >> n >> m;

	info.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, vector<int>(2, INT_MAX));

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		info[a].push_back({b,c});
	}

	int start, end;
	cin >> start >>end;

	priority_queue<pair<int, int>> pq;
	pq.push({0,start});
	dist[start][0] = 0;
	dist[start][1] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if (pos == end) 
			break;
		
		for (auto a : info[pos]) {
			if (dist[a.first][0] > dist[pos][0] + a.second) {
				dist[a.first][0] = dist[pos][0] + a.second;
				dist[a.first][1] = pos;
				pq.push({-dist[a.first][0], a.first});
			}
		}
	}

	cout << dist[end][0]<<'\n';
	stack<int> path;

	while (end != 0) {
		path.push(end);
		end = dist[end][1];
	}
	cout << path.size()<<"\n";
	
	while (!path.empty()) {
		cout << path.top()<<" ";
		path.pop();
	}
	
	return 0;
}