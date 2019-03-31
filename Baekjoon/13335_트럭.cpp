#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int bj_13335() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, w, l;
	cin >> n >> w >> l;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		q.push(t);
	}
	
	int weight = q.front();
	q.pop();
	vector<pair<int,int>> bridge;
	bridge.push_back({weight,1});
	int ans = 1;
	int idx = 0;
	while (!q.empty()) {
		ans++;
		for (int j = idx; j < bridge.size(); ++j) {
			bridge[j].second++;
		}

		// 다리 탈출 조건
		if (idx<bridge.size() && bridge[idx].second > w) {
			weight -= bridge[idx].first;
			++idx;
		}

		// 다리 진입 조건
		int cw = q.front();
		if (bridge.size()-idx + 1 <= w && weight + cw <= l) {
			q.pop();
			bridge.push_back({cw,1});
			weight += cw;
		}
	}

	while (idx != bridge.size()) {
		ans++;
		for (int j = idx; j < bridge.size(); ++j) {
			bridge[j].second++;
		}
		if (bridge[idx].second > w) {
			weight -= bridge[idx].first;
			++idx;
		}
	}
	cout << ans;

	return 0;
}