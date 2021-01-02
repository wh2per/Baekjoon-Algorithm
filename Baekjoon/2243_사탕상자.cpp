#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int arr[MAX];
int tree[MAX*4];

void update(int node, int idx, int left, int right, int x) {		// À§·Î ¿Ã¶ó°¡¸é¼­ push
	if (idx < left || right < idx)
		return;
	tree[node] += x;

	if (left != right) {
		update(node * 2, idx, left, (left + right) / 2, x);
		update(node * 2 + 1, idx, (left + right) / 2 + 1, right, x);
	}
}

int query(int node, int start, int end, int x) {
	if (start==end)
		return start;

	if (tree[node * 2] >= x)
		return query(node * 2, start, (start + end) / 2, x);
	else
		return query(node*2+1, (start+end)/2+1, end,x-tree[node*2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		if (a == 1) {			// »çÅÁ ²¨³»±â
			int b;
			cin >> b;
			int ans = query(1,1,MAX,b);
			cout << ans << "\n";
			update(1,ans,1,MAX,-1);
		}
		else {					// »çÅÁ ³Ö±â
			int b, c;
			cin >> b >> c;
			update(1,b,1,MAX,c);
		}
	}

	return 0;
}