#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
ll arr[100001];
ll tree[1 << 18];
ll lazy[1 << 18];

void update_lazy(int node, int start, int end)
{
	if (lazy[node] == 0)
		return;
	tree[node] = (end - start + 1) - tree[node];
	
	if (start != end){
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}

	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);

	if (left > end || right < start)
		return;

	if (left <= start && end <= right){
		tree[node] = (end - start + 1) - tree[node];

		if (start != end){
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right);
	update_range(node * 2 + 1, mid + 1, end, left, right);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);

	if (left > end || right < start)
		return 0;

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("./input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 0)
			update_range(1, 1, n, t2, t3);
		else
			cout << query(1, 1, n, t2, t3) << '\n';
	}

	return 0;
}