#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<long> arr;
vector<long> tree;

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	}
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && right >= end)
		return tree[node];

	long long mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int height = (int)ceil(log2(n));
	int size = 1 << (height + 1);

	arr.assign(n + 1, 0);
	tree.assign(size, 0);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	while (m--) {
		int a, b;
		cin >> a >> b;

		if (a > b)
			swap(a, b);
		cout << query(1, 1, n, a, b) << "\n";
	}

	return 0;
}
