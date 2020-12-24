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
int tree[1 << 18];

int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
	}
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return INT_MAX;
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) >> 1;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int update(int node, int start, int end, int idx) {
	if (idx < start || idx > end)
		return tree[node];
	if (start == end)
		return tree[node] = arr[idx];

	int mid = (start + end) >> 1;
	return tree[node] = min(update(node * 2, start, mid, idx), update(node * 2 + 1, mid + 1, end, idx));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {		// update
			arr[b] = c;
			update(1, 1, n, b);
		}
		else {		// query
			cout << query(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}