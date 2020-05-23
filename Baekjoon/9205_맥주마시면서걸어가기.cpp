#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

bool visit[101];
vector<pair<int, int>> mart;
int fx, fy;
bool flag;
int n;

void dfs(int hx, int hy) {
	int dist = abs(fx - hx) + abs(fy - hy);

	if (flag || dist <= 1000) {
		flag = true;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visit[i])
			continue;

		dist = abs(mart[i].first - hx) + abs(mart[i].second - hy);

		if (dist > 1000)
			continue;
		else {
			visit[i] = true;
			dfs(mart[i].first, mart[i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		int hx, hy;
		cin >> hx >> hy;

		mart.clear();
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			mart.push_back({x,y});
		}
		
		cin >> fx >> fy;

		flag = false;
		dfs(hx,hy);

		if (flag)
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}