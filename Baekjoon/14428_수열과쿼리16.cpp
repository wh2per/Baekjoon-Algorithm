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
		return tree[node] = start;

	int a = init(node * 2, start, (start + end) / 2);
	int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
	if (arr[a] == arr[b])
		return tree[node] = min(a, b);
	if (arr[a] > arr[b])
		swap(a, b);
	return tree[node] = a;
}

int update(int node, int idx, int left, int right) {
	if (idx < left || idx > right)
		return tree[node];
	if (left == right)
		return idx;

	int a = update(node * 2, idx, left, (left + right) / 2);
	int b = update(node * 2 + 1, idx, (left + right) / 2 + 1, right);
	if (arr[a] == arr[b])
		return tree[node] = min(a, b);
	if (arr[a] > arr[b])
		swap(a, b);
	return tree[node] = a;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) >> 1;

	int a = query(node * 2, start, mid, left, right);
	int b = query(node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] == arr[b])
		return min(a, b);
	if (arr[a] > arr[b])
		return b;
	else
		return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n, q;
	cin >> n;

	arr[0] = INT_MAX;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	cin >> q;
	while (q--) {
		int a, b, c;

		cin >> a >> b >> c;
		if (a == 1) {		// update
			arr[b] = c;
			update(1, b, 1, n);
		}
		else 			// query
			cout << query(1, 1, n, b, c) << "\n";
	}

	return 0;
}