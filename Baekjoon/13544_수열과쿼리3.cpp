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

const int tree_size = 1 << 18;
int arr[100001];
vector<int> tree[tree_size];
int last_ans;

void update(int node, int idx, int left, int right, int x) {
	if (idx < left || right < idx)
		return;
	tree[node].push_back(x);

	if (left != right) {
		update(node * 2, idx, left, (left + right) / 2, x);
		update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
	}
}

int query(int node, int start, int end, int left, int right, int x) {
	if (right < start || left > end)
		return 0;
	if (start <= left && right <= end) // 범위 안에 포함된 다면
		return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();		// 현재 몇번째 수인지 리턴

	return query(node * 2, start, end, left, (left + right) / 2, x) + query(node * 2 + 1, start, end, (left + right) / 2 + 1, right, x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(1, i, 1, n, arr[i]);
	}

	for (int i = 0; i < tree_size; ++i)
		sort(tree[i].begin(), tree[i].end());

	int m;
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		int i = a ^ last_ans;
		int j = b ^ last_ans;
		int k = c ^ last_ans;

		last_ans = (j - i + 1) - query(1, i, j, 1, n, k);
		cout << last_ans << "\n";
	}


	return 0;
}