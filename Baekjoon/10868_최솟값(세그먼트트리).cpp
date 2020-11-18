#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;

typedef long long ll;

int getIndex(int n) {			// 배열크기 정하기
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

ll init(vector<ll>& a, vector<ll>& tree, int start, int end, int node)
{ // 세그먼트 트리 생성
	if (start == end)
		return tree[node] = a[start]; // 리프 노드에 도달한 경우

	int mid = (start + end) / 2;
	// 재귀적으로 두 부분을 나누어 그 중 최소값을 자기 자신으로 한다.
	return tree[node] = min(init(a, tree, start, mid, node * 2), init(a, tree, mid + 1, end, node * 2 + 1));
}

// left ~ right 까지의 최소값을 구함, start, end : 시작, 끝 인덱스
ll search_min(vector<ll>& tree, int start, int end, int node, int left, int right)
{
	// 범위를 벗어난 경우
	if (left > end || right < start)
		return LLONG_MAX;

	// 범위 내에 포함된 경우 현재 트리의 값 리턴(구간합)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return min(search_min(tree, start, mid, node * 2, left, right), search_min(tree, mid + 1, end, node * 2 + 1, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	vector<ll> a(n);
	int tree_size = getIndex(n); // 세그먼트 트리의 크기
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 0, n - 1, 1); // 세그먼트 트리 생성

	while (m--)
	{
		int t2, t3;
		cin >> t2 >> t3;
		cout << search_min(tree, 0, n - 1, 1, t2 - 1, t3 - 1) << '\n';
	}

	return 0;
}