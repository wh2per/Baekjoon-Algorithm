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
		if (arr[start] % 2 == 0)
			++tree[node].second;
		else
			++tree[node].first;
		return tree[node];
	}

	pair<int, int> p1 = init(node * 2, start, (start + end) / 2);
	pair<int, int> p2 = init(node * 2 + 1, (start + end) / 2 + 1, end);

	return tree[node] = { p1.first + p2.first,p1.second + p2.second };
}

void update(int node, int left, int right, int idx, int odd, int even) {
	if (idx < left || idx > right)	// ¹üÀ§ ¹Û
		return;
	tree[node].first += odd;
	tree[node].second += even;

	if (left != right) {
		update(node * 2, left, (left + right) / 2, idx, odd, even);
		update(node * 2 + 1, (left + right) / 2 + 1, right, idx, odd, even);
	}
}

pair<int, int> query(int node, int left, int right, int start, int end) {
	if (start > right || end < left)
		return { 0,0 };
	if (left >= start && right <= end)
		return tree[node];

	pair<int, int> p1 = query(node * 2, left, (left + right) / 2, start, end);
	pair<int, int> p2 = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

	return { p1.first + p2.first,p1.second + p2.second };
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
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {		// update
			if (arr[b] % 2 == 0) {		// ±âÁ¸ °ªÀÌ Â¦¼ö
				if (c % 2 != 0)
					update(1, 1, n, b, 1, -1);
			}
			else {		// ±âÁ¸ °ªÀÌ È¦¼ö
				if (c % 2 == 0)
					update(1, 1, n, b, -1, 1);
			}
			arr[b] = c;
		}
		else if (a == 2) 	// query Â¦¼ö
			cout << query(1, 1, n, b, c).second << "\n";
		else 				// query È¦¼ö
			cout << query(1, 1, n, b, c).first << "\n";
	}

	return 0;
}