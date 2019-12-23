#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp_score(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second > p2.second)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<pair<int, int>> v;

	for (int i = 1; i <= 5; ++i) {
		int score = 0;
		for (int j = 0; j < 4; ++j) {
			int n;
			cin >> n;
			score += n;
		}
		v.push_back({i,score});
	}

	sort(v.begin(), v.end(), cmp_score);
	cout << v[0].first << " " << v[0].second;
	return 0;
}