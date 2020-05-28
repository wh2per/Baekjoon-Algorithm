#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	set<vector<int>> s;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	do {
		vector<int> arr;
		for (int i = 0; i < m; ++i)
			arr.push_back(v[i]);

		s.insert(arr);
	} while (next_permutation(v.begin(), v.end()));

	for (auto a : s) {
		for (int i = 0; i < m; ++i)
			cout << a[i] << " ";
		cout << '\n';
	}

	return 0;
}