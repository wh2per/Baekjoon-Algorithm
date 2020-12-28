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

long long arr[1000001];
long long tree[1 << 21];

void update(int node, int idx, int left, int right, int x) {
	if (idx < left || right < idx)
		return;
	tree[node] += x;
	if (left != right) {
		update(node * 2, idx, left, (left + right) / 2, x);
		update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
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

	//freopen("sample_input.txt", "r", stdin);

	int n, q;
	cin >> n >> q;

	while (q--) {
		int a, b, c;

		cin >> a >> b >> c;
		if (a == 1) 		// update
			update(1, b, 1, n, c);
		else 			// query
			cout << query(1, 1, n, b, c) << "\n";
	}
	return 0;
}