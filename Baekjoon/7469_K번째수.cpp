#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 1 << 18;
int arr[100001];
vector<int> tree[MAX];

void update(int node, int idx, int left, int right, int x) {		// 위로 올라가면서 push
	if (idx < left || right < idx)
		return;
	tree[node].push_back(x);

	if (left != right) {
		update(node * 2, idx, left, (left + right) / 2, x);
		update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
	}
}

int query(int node, int start, int end, int left, int right, int x) {
	if (right<start || left>end)
		return 0;
	if (start <= left && right <= end)		// 범위 안에 포함되면 다면
		return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();	// 현재 몇번째 수인지 리턴

	return query(node * 2, start, end, left, (left + right) / 2, x) + query(node * 2 + 1, start, end, (left + right) / 2 + 1, right, x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(1, i, 1, n, arr[i]);
	}

	for (int i = 0; i < MAX; ++i)
		sort(tree[i].begin(), tree[i].end());

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		int left = -1000000000, right = 1000000000;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (query(1, a, b, 1, n, mid) < c)
				left = mid + 1;
			else
				right = mid - 1;
		}
		cout << left << "\n";
	}

	return 0;
}