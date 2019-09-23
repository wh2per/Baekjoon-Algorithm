#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// 다익스트라

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector < vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a].push_back({ b,c });
		info[b].push_back({ a,c });
	}

	int s, e;
	cin >> s >> e;

	vector<int> dist1(n + 1, INT_MAX);		// 1
	vector<int> dist2(n + 1, INT_MAX);		// s
	vector<int> dist3(n + 1, INT_MAX);		// e

	dist1[1] = 0;		// 시작점 초기화
	dist2[s] = 0;		// 시작점 초기화
	dist3[e] = 0;		// 시작점 초기화
	priority_queue<pair<int, int>> pq1;
	priority_queue<pair<int, int>> pq2;
	priority_queue<pair<int, int>> pq3;
	pq1.push({ 0,1 });
	pq2.push({ 0,s });
	pq3.push({ 0,e });

	while (!pq1.empty()) {
		int cost = pq1.top().first;
		int pos = pq1.top().second;
		pq1.pop();

		for (int i = 0; i < info[pos].size(); ++i) {
			int next = info[pos][i].first;
			int ncost = info[pos][i].second;

			if (dist1[next] > dist1[pos] + ncost) {		// 거리를 갱신해야 할 경우
				dist1[next] = dist1[pos] + ncost;
				pq1.push({ -dist1[next], next });			// 계속 진행하기 위해 큐에 삽입
			}
		}
	}

	while (!pq2.empty()) {
		int cost = pq2.top().first;
		int pos = pq2.top().second;
		pq2.pop();

		for (int i = 0; i < info[pos].size(); ++i) {
			int next = info[pos][i].first;
			int ncost = info[pos][i].second;

			if (dist2[next] > dist2[pos] + ncost) {		// 거리를 갱신해야 할 경우
				dist2[next] = dist2[pos] + ncost;
				pq2.push({ -dist2[next], next });			// 계속 진행하기 위해 큐에 삽입
			}
		}
	}

	while (!pq3.empty()) {
		int cost = pq3.top().first;
		int pos = pq3.top().second;
		pq3.pop();

		for (int i = 0; i < info[pos].size(); ++i) {
			int next = info[pos][i].first;
			int ncost = info[pos][i].second;

			if (dist3[next] > dist3[pos] + ncost) {		// 거리를 갱신해야 할 경우
				dist3[next] = dist3[pos] + ncost;
				pq3.push({ -dist1[next], next });			// 계속 진행하기 위해 큐에 삽입
			}
		}
	}
	// dist(1~s) + dist(s~e) + dist(e~n)
	// dist(1~e) + dist(e~s) + dist(s~n)
	// dist(1~n)
	if (dist1[s] == INT_MAX || dist2[e] == INT_MAX || dist3[n] == INT_MAX) {
		if (dist1[e] == INT_MAX || dist3[s] == INT_MAX || dist2[n] == INT_MAX)
			cout << -1;
		else
			cout << dist1[e] + dist3[s] + dist2[n];
	}
	else {
		if (dist1[e] == INT_MAX || dist3[s] == INT_MAX || dist2[n] == INT_MAX)
			cout << dist1[s] + dist2[e] + dist3[n];
		else
			cout << min(dist1[e] + dist3[s] + dist2[n], dist1[s] + dist2[e] + dist3[n]);
	}
		
	return 0;
}