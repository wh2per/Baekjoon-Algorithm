#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;
int n, k;

bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b) {
	if (a.first.second > b.first.second)
		return true;
	else if (a.first.second == b.first.second) {
		if (a.second.first > b.second.first)
			return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second)
				return true;
			else if (a.second.second == b.second.second)
				return a.first.first==k;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<pair<pair<int, int>, pair<int, int>>> v;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ {a,b},{c,d} });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; ++i) {
		if (v[i].first.first == k) {
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}