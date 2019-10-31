#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

bool cmp_tree(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first < p2.first)
		return true;
	else if (p1.first == p2.first) {
		if (p1.second < p2.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> tree;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			tree.push_back({ a,b });
		}

		queue<pair<int, int>> q;
		int ans = 0;
		while (tree.size() != 0) {
			sort(tree.begin(), tree.end(), cmp_tree);
			for (int i = 0; i < tree.size(); ++i)
				q.push(tree[i]);
			tree.clear();
			++ans;
			int pw = -1;

			while (!q.empty()) {
				int cl = q.front().first;
				int cw = q.front().second;
				q.pop();
				if (pw > cw) {

					tree.push_back({ cl,cw });
				}
				else
					pw = cw;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}