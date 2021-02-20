#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int arr[1000001];
int tree[1 << 21];
int ans;
int sub;

int GCD(int x, int y) {
	if (y == 0) 
		return x;
	else 
		return GCD(y, x % y);
	return 0;
}

int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		return tree[node] = GCD(init(node * 2, start, mid),init(node * 2 + 1, mid + 1, end));
	}
}

int update(int node, int start, int end, int idx, int diff) {
	if (idx < start || idx > end)	// 범위 밖
		return tree[node];
	if(start==end)
		return tree[node]=arr[idx];		// GCD(x,0) = x

	int mid = (start + end) >> 1;
	return tree[node] = GCD(update(node * 2, start, mid, idx, diff), update(node * 2 + 1, mid + 1, end, idx, diff));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n);		// 세그먼트 트리

	ans = -1;
	for (int i = 1; i <= n; ++i) {
		int target = arr[i];
		arr[i] = 0;
		update(1,1,n,i,0);
		
		if (target % tree[1] != 0 && ans < tree[1]) {
			ans = tree[1];
			sub = target;
		}
		arr[i] = target;
		update(1, 1, n, i, target);
	}

	if (ans == -1)
		cout << "-1";
	else
		cout << ans <<" "<<sub;

	return 0;
}