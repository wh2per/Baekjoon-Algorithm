#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int n, m, b;
	cin >> n >> m >> b;

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int h;
			cin >> h;
			v.push_back(h);
		}
	}

	sort(v.begin(), v.end());

	int start = v[0];
	int end = v[v.size() - 1];

	int ans_h = 0, ans_t = INT_MAX;

	for (int i = start; i <= end; ++i) {
		int left = b;
		int time = 0;
		bool flag = true;

		for (int j = 0; j < v.size(); ++j) {
			int diff = i - v[j];
			if (diff > 0) {		// 쌓아야 하는거
				time += diff;
				left -= diff;
			}	
			else {			// 제거해야 하는거
				time -= 2*diff;
				left -= diff;
			}
		}

		if (left >= 0 && ans_t >= time) {
			ans_h = i;
			ans_t = time;
		}
	}

	cout << ans_t << " " << ans_h;

	return 0;
}