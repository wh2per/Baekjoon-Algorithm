#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1<<21];
ll lazy[1<<21];

void update_lazy(int node, int start, int end)
{
	// lazy가 0이면 return;
	if (lazy[node] == 0)
		return;

	// 자식 노드가 있는 수 만큼 lazy값에 곱하여 더한다.
	// 자식에게 lazy를 분배하니 자식이 return으로 더해주지 못한 값을 직접 더한다.
	tree[node] += (end - start + 1) * lazy[node];

	// leaf가 아니면
	// 자식에게 lazy를 물려준다.
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	// 물려준 후 lazy는 초기화
	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, ll val)
{
	/*
		순서 ::
		1. lazy가 존재하면 업데이트 해준다.(tree[node] 변화)
		2. val을 더해준다.(자식수가 있는 만큼)
		2에서 자식 수만큼 더해주는 이유는 자식들은 아직 lazy가 업데이트 되지 않았기 때문
	*/
	// 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
	update_lazy(node, start, end);

	// 하나도 속하지 않는다면 return;
	if (left > end || right < start)
		return;

	// 원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right)
	{
		// 자식 노드가 있는 수 만큼 val을 곱해서 더해준다.
		// 자식이 return으로 더해주는 형태가 아니니 직접 더한다.
		tree[node] += (end - start + 1) * val;

		if (start != end)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1,end, left, right, val);

	// 구간이 걸쳐서 속해 있다면 자식 노드를 이용하여 부모 노드를 업데이트 한다.
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll init(int node, int start, int end)
{ // 세그먼트 트리 생성
	if (start == end)
		return tree[node] = arr[start]; // 리프 노드에 도달한 경우

	int mid = (start + end) / 2;
	// 재귀적으로 두 부분을 나누어 그 합을 자기 자신으로 한다.
	return tree[node] = init(node * 2,start, mid) + init(node * 2 + 1, mid + 1, end);
}

// left ~ right 까지의 구간합을 구함, start, end : 시작, 끝 인덱스
ll query(int node, int start, int end, int left, int right)
{
	// update이후 남은 lazy를 해당하는 구간을 sum 할 때 업데이트 해준다.
	update_lazy(node, start, end);

	// 범위를 벗어난 경우
	if (left > end || right < start)
		return 0;

	// 범위 내에 포함된 경우 현재 트리의 값 리턴(구간합)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1,0, n); // 세그먼트 트리 생성

	k += m; // m + k번 반복
	while (k--)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
		{
			ll t4;
			cin >> t4;

			update_range(1, 1, n, t2, t3, t4);
		}
		else if (t1 == 2)
		{
			cout << query(1, 1, n, t2, t3) << '\n';
		}
	}

	return 0;
}