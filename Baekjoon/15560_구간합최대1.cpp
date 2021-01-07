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

/*
A[i]를 U * A[i] + V로 치환
max(A[i] + ... + A[j])가 최대가 되는 연속 구간 최대 합
*/
const int inf = 1e9;

struct info {
	int ls;		// 왼쪽 구간 최대합
	int rs;		// 오른쪽 구간 최대합
	int lrs;	// 좌우 최대합
	int mxs;	// 위 2개중에 최대
	info(int ls=-inf, int rs = -inf, int lrs=0, int mxs = -inf) :ls(ls), rs(rs), lrs(lrs), mxs(mxs) {}
};

int arr[1001];
info tree[1 << 11];

info merge(const info& a, const info& b) {
	return { max(a.ls, a.lrs + b.ls), max(a.rs + b.lrs, b.rs), a.lrs + b.lrs, max({a.mxs,b.mxs,a.rs + b.ls}) };
}

info query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return { -inf, -inf, 0, -inf };
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) >> 1;
	info info1 = query(node * 2, start, mid, left, right);
	info info2 = query(node * 2 + 1, mid + 1, end, left, right);
	return merge(info1, info2);
}


void update(int node, int start, int end, int idx, int x) {
	if (idx < start || idx > end)
		return;

	if (start != end) {
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, idx, x);
		update(node * 2 + 1, mid + 1, end, idx, x);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
	else
		tree[node] = { x,x,x,x };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, q, u, v;
	cin >> n >> q >> u >> v;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(1, 1, n, i, u * arr[i] + v);
	}

	while (q--) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {		// max(u * (arr[i]+...+arr[j]) + v*(j-i) )  query
			cout << query(1, 1, n, a, b).mxs - v << "\n";
		}
		else {		// arr[a]를 b로 update
			arr[a] = b;
			update(1, 1, n, a, u * b + v);
		}
	}

	return 0;
}