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

long long arr[100001];
long long tree[1 << 18];

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
	}
}

long long update(int node, int idx, int left, int right, int x) {
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] = x;

	return tree[node] = min(update(node * 2, idx, left, (left + right) / 2, x), update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x));
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return LLONG_MAX;
	if (left <= start && right >= end)
		return tree[node];

	long long mid = (start + end) >> 1;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n, q;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1, 1, n);

	cin >> q;
	while (q--) {
		int a;

		cin >> a;
		if (a == 1) {		// update
			int b, c;
			cin >> b >> c;

			update(1, b, 1, n, c);
			arr[b] = c;
		}
		else {			// query
			int ans = query(1, 1, n, 1, n);
			for (int i = 1; i <= n; ++i) {
				if (arr[i] == ans) {
					cout << i << "\n";
					break;
				}
			}
		}
	}

	return 0;
}