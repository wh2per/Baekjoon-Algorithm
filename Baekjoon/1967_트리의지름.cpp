#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;

struct node {
	int value;
	vector<node*> child;
};
struct node tree[10001];

int postFix(node a) {
	vector<int> cost;

	for (auto c : a.child)
		cost.push_back(postFix(*c));

	if (cost.size() != 0)
		sort(cost.begin(), cost.end());

	int ret = 0;
	if (cost.size() > 1) {
		int max1 = cost.back();
		int max2 = cost[cost.size() - 2];
		ans = max(ans, max1 + max2);
	}

	if (cost.size() > 0)
		ret = *max_element(cost.begin(), cost.end());
	return ret + a.value;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ans = 0;

	int n;
	cin >> n;

	tree[1].value = 0;

	for (int i = 0; i < n - 1; ++i) {
		int parent, child, value;
		cin >> parent >> child >> value;

		tree[parent].child.push_back(&tree[child]);
		tree[child].value = value;
	}

	ans = max(ans, postFix(tree[1]));
	cout << ans;
	return 0;
}