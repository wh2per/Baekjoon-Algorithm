#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1 << 21];

// 세그먼트 트리 생성
ll init(int node, int start, int end){ 
	if (start == end)
		return tree[node] = arr[start]; // 리프 노드에 도달한 경우

	int mid = (start + end) / 2;
	// 재귀적으로 두 부분을 나누어 그 합을 자기 자신으로 한다.
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// left ~ right 까지의 구간합을 구함, start, end : 시작, 끝 인덱스
ll sum(int node, int start, int end, int left, int right){
	// 범위를 벗어난 경우
	if (left > end || right < start)
		return 0;

	// 범위 내에 포함된 경우 현재 트리의 값 리턴(구간합)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

// index : 수정할 노드의 인덱스, dif : 노드의 차이값
void update(int node, int start, int end, int index, ll diff){
	// 범위를 벗어난 경우
	if (index < start || index > end)
		return;
	tree[node] += diff; // 수정할 노드가 포함된 노드들의 값을 수정

	if (start == end)
		return; // 수정할 노드를 찾은 경우

	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n); // 세그먼트 트리 생성

	k += m; // m + k번 반복
	while (k--){
		long long t1, t2, t3;
		cin >> t1 >> t2 >> t3;

		if (t1 == 1){
			ll diff = (ll)(t3 - arr[t2]); // 차이값 저장
			arr[t2] = t3; // a[t2] 값 변경
			update(1, 1, n, t2, diff);
		}
		else if (t1 == 2)
			cout << sum(1, 1, n, t2, t3) << '\n';
	}

	return 0;
}