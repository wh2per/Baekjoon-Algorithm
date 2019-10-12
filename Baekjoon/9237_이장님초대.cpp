#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> tree(n);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i];
	}

	sort(tree.begin(), tree.end());

	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = max(ans, tree[i] + n - i + 1);
	}
	cout << ans;
	return 0;
}