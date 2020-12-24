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

int n, k;
long long arr[100001];
long long tree[1 << 18];

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end);
	}
}

long long update(int node, int idx, int left, int right, int x) {	
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] = x;

	return tree[node] = update(node * 2, idx, left, (left + right) / 2, x) * update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && right >= end)
		return tree[node];

	long long mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	while (cin >> n >> k) {
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));

		for (int i = 1; i <= n; ++i) {
			int num;
			cin >> num;
			if (num > 0)
				arr[i] = 1;
			else if (num < 0)
				arr[i] = -1;
			else
				arr[i] = 0;
		}

		init(1, 1, n);

		while (k--) {
			char c;
			int a, b;

			cin >> c >> a >> b;
			if (c == 'C') {		// update
				if (b > 0)
					update(1, a, 1, n, 1);
				else if (b < 0)
					update(1, a, 1, n, -1);
				else
					update(1,a,1,n,0);
			}
			else {			// query
				long long ans = query(1, 1, n, a, b);
				if (ans > 0)
					cout << "+";
				else if (ans < 0)
					cout << "-";
				else
					cout << "0";
			}
		}
		cout << "\n";
	}

	return 0;
}