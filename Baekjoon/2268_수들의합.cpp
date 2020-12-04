#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

vector<long long> arr;
vector<long long> tree;

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	}
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

	freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	int height = (int)ceil(log2(n));
	int size = 1 << (height + 1);

	arr.assign(n + 1, 0);
	tree.assign(size, 0);

	init(1, 1, n);

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {		// sum
			if (b > c)
				swap(b, c);
			cout << query(1, 1, n, b, c) << "\n";
		}
		else {				// modify
			long long diff = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, diff);
		}
	}

	return 0;
}