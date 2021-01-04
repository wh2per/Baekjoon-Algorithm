#include <iostream>
#include <vector>
using namespace std;

const int MAX = 65540;
long long arr[250001];
long long tree[MAX * 4];

long long update(int node, int idx, int left, int right, int x) {
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] += x;
	else
		return tree[node] = update(node * 2, idx, left, (left + right) / 2, x) + update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
}

long long query(int node, int x, int start, int end) {
	if (start == end)
		return start;
	if (tree[node * 2] >= x)
		return query(node * 2, x, start, (start + end) / 2);
	else
		return query(node * 2 + 1, x - tree[node * 2], (start + end) / 2 + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long ans = 0;

	for (int i = 0; i < k; ++i) {
		cin >> arr[i];
		update(1, arr[i], 0, MAX, 1);		// arr[i]의 갯수를 한개씩 추가
	}

	ans += query(1, (k + 1) / 2, 0, MAX);		// 첫번째 구간
	for (int i = k; i < n; ++i) {
		cin >> arr[i];
		update(1, arr[i], 0, MAX, 1);		// arr[i]의 갯수를 한개 증가
		update(1, arr[i - k], 0, MAX, -1);	// arr[i-k]의 갯수를 한개 감소
		ans += query(1, (k + 1) / 2, 0, MAX);
	}
	cout << ans;
	return 0;
}