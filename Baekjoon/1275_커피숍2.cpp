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

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end)
		return;
	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, q;
	cin >> n >> q;

	int height = (int)ceil(log2(n));
	int size = 1 << (height + 1);

	arr.assign(n + 1, 0);
	tree.assign(size, 0);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a > b)
			swap(a, b);
		cout << query(1, 1, n, a, b) << "\n";

		long long diff = d - arr[c];
		arr[c] = d;
		update(1, 1, n, c, diff);
	}

	return 0;
}