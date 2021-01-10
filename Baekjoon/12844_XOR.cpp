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

typedef long long ll;
int arr[500001];
int tree[1<<21];
int lazy[1<<21];

int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] = init(node*2, start,(start+end)/2) ^ init(node*2+1, (start + end) / 2+1,end);
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] == 0)
		return;
	tree[node] ^= lazy[node] * ((end - start + 1)%2);		// 범위내 갯수만큼 더하기

	if (start != end) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}

	lazy[node] = 0;
}

int update_range(int node, int start, int end, int left, int right,int x) {
	update_lazy(node, start, end);

	if (left > end || right < start)
		return tree[node];

	if (left <= start && end <= right) {
		tree[node] ^= x * ((end - start + 1) % 2);

		if (start != end) {
			lazy[node * 2] ^= x;
			lazy[node * 2 + 1] ^= x;
		}
		return tree[node];
	}

	int mid = (start + end) / 2;
	return tree[node] = update_range(node * 2, start, mid, left, right,x) ^ update_range(node * 2 + 1, mid + 1, end, left, right,x);
}

int query(int node, int start, int end, int left, int right){
	update_lazy(node, start, end);

	if (left > end || right < start)
		return 0;

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int q;
	cin >> q;

	init(1,0,n-1);

	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {		// update  b~c xor
			int k;
			cin >> k;

			if (b > c)
				swap(b, c);
			update_range(1,0,n-1,b,c,k);
		}
		else {		// query		b~c까지 모두 xor한다음 출력
			if (b > c)
				swap(b, c);
			cout << query(1,0,n-1,b,c)<<"\n";
		}
	}

	return 0;
}