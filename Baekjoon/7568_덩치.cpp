#include <iostream>
#include <vector>
using namespace std;

int bj_7568() {
	int t;
	cin >> t;
	vector<pair<int, int>> v;
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < t; ++i) {
		int ans = 1;
		for (int j = 0; j < t; ++j) {
			if (i!=j && v[i].first < v[j].first && v[i].second < v[j].second)
				++ans;
		}
		cout << ans << " ";
	}
	return 0;
}