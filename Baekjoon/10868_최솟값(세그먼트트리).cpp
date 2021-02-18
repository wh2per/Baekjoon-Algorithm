#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;

typedef long long ll;
ll arr[100001];
ll tree[1<<18];

ll init(int node, int start, int end)
{ // 세그먼트 트리 생성
	if (start == end)
		return tree[node] = arr[start]; // 리프 노드에 도달한 경우

	int mid = (start + end) / 2;
	// 재귀적으로 두 부분을 나누어 그 중 최소값을 자기 자신으로 한다.
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

// left ~ right 까지의 최소값을 구함, start, end : 시작, 끝 인덱스
ll search_min(int node, int start, int end, int left, int right)
{
	// 범위를 벗어난 경우
	if (left > end || right < start)
		return LLONG_MAX;

	// 범위 내에 포함된 경우 현재 트리의 값 리턴(구간합)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return min(search_min(node * 2, start, mid, left, right), search_min(node * 2 + 1, mid + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1,1,n); // 세그먼트 트리 생성

	while (m--){
		int t2, t3;
		cin >> t2 >> t3;
		cout << search_min(1,1,n, t2, t3) << '\n';
	}

	return 0;
}