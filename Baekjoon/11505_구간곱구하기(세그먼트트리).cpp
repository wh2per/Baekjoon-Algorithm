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
long long tree[1<<21];
int n, m, k;

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = init(node*2,start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end) % 1000000007;
}

long long update(int node, int idx, int left, int right, int x) {
	if (idx < left || right < idx)		// 범위 벗어나면
		return tree[node];
	if (left == right)		
		return tree[node] = x;
	return tree[node] = update(node * 2, idx, left, (left + right) / 2, x) * update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x) % 1000000007;
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)		// 범위 밖
		return 1;
	if (left <= start && right >= end)		// 범위 안
		return tree[node];

	return query(node * 2, start, (start+end)/2, left, right) * query(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % 1000000007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	init(1,1,n);

	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) 		// update
			update(1, b, 1, n, c);
		else 			// query
			cout << query(1,1,n,b,c)<<"\n";
	}

	return 0;
}