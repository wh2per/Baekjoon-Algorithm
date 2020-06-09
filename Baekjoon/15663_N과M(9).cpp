#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	set<vector<int>> s;

	vector<int> check(n, 0);
	for (int i = 0; i < m; ++i)
		check[i] = -1;

	do {
		do {
			vector<int> temp;

			for (int i = 0; i < n; ++i) {
				if (check[i] == -1)
					temp.push_back(v[i]);
			}

			s.insert(temp);
		} while (next_permutation(check.begin(), check.end()));
	} while (next_permutation(v.begin(), v.end()));
	

	for (auto a : s) {
		for (auto aa : a)
			cout << aa << " ";
		cout << endl;
	}

	return 0;
}