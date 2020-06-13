#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

vector<int> v, ans;
int n, m;

void go(int cnt, int idx) {
	if (cnt == m) {
		for (auto k : ans)
			cout << k << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i < n; i++) {
		ans.push_back(v[i]);
		go(cnt + 1, i);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> n >> m;


	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		if (find(v.begin(), v.end(), num) == v.end())
			v.push_back(num);
	}

	sort(v.begin(), v.end());
	n = v.size();
	go(0, 0);

	return 0;
}