#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

// 위상정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> info(n + 1);
	vector<vector<int>> reverse(n + 1);
	map<pair<int, int>, int> cost_info;
	vector<int> degree(n + 1,0);
	vector<int> cost(n + 1,0);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a].push_back(b);					// 인접행렬 정보 저장
		reverse[b].push_back(a);
		if (cost_info.count({ a,b }) > 0) {		// 비용정보 저장
			if (cost_info[{a, b}] < c)
				cost_info[{a, b}] = c;
		}
		else
			cost_info.insert({ { a,b },c });
		++degree[b];							// 차수 증가
	}

	int s, e;
	cin >> s >> e;

	queue<int> q1;
	q1.push(s);		//  시작점 추가

	while (!q1.empty()) {
		int d = q1.front();
		q1.pop();
		for (auto a : info[d]) {
			--degree[a];
			cost[a] = max(cost[d] + cost_info[{d,a}], cost[a]);
			if (degree[a] == 0)
				q1.push(a);
		}
	}

	int cnt = 0;
	queue<int> q2;
	q2.push(e);		//  도착점 추가
	vector<vector<bool>> check(n+1, vector<bool>(n+1,false));

	while (!q2.empty()) {
		int d = q2.front();
		q2.pop();
		for (auto a : reverse[d]) {
			if (cost[d] == cost[a] + cost_info[{a,d}] && !check[d][a]) {
				check[d][a] = true;
				q2.push(a);
				++cnt;
			}
		}
	}

	cout << cost[e] << "\n" << cnt;

	return 0;
}