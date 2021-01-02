#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int arr[100001];
pair<int, int> tree[1 << 18];

pair<int, int> init(int node, int start, int end) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = arr[start];
		return tree[node];
	}

	pair<int, int> p1 = init(node * 2, start, (start + end) / 2);
	pair<int, int> p2 = init(node * 2 + 1, (start + end) / 2 + 1, end);

	return tree[node] = { max(p1.first,p2.first),min(p1.second,p2.second) };
}

pair<int, int> query(int node, int left, int right, int start, int end) {
	if (start > right || end < left)
		return { INT_MIN,INT_MAX };
	if (left >= start && right <= end)
		return tree[node];

	pair<int, int> p1 = query(node * 2, left, (left + right) / 2, start, end);
	pair<int, int> p2 = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

	return { max(p1.first,p2.first),min(p1.second,p2.second) };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >>m;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	while (m--) {
		int a, b;
		cin >> a >> b;

		pair<int, int> ans = query(1, 1, n, a, b);
		cout << ans.second << " " << ans.first << "\n";
	}

	return 0;
}