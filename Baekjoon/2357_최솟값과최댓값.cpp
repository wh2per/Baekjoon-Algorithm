#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int getindex(int n) {			// 배열크기 정하기
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int bj_2357() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	int size = getindex(n);
	int start = size - n - 1;
	vector <int> v1(size, 0);
	vector <int> v2(size, 0);
	for (int i = size - n; i < size; ++i) {
		int num;
		cin >> num;
		v1[i] = v2[i] = num;
	}

	int p = (size - 1) / 2;				// 구간합 구하기
	for (int i = p; i > 0; --i) {
		v1[i] = min(v1[i * 2], v1[i * 2 + 1]);
		v2[i] = max(v2[i * 2], v2[i * 2 + 1]);
	}

	for (int k = 0; k < q; ++k) {
		int x, y;
		cin >> x >> y;

		// 최소값 구하기
		int l = x + start;
		int r = y + start;
		int ans = INT_MAX;
		while (l <= r) {
			ans = min(ans, min(v1[l], v1[r]));
			l = (l + 1) >> 1;
			r = (r - 1) >> 1;
		}
		cout << ans << " ";

		// 최대값 구하기
		l = x + start;
		r = y + start;
		ans = -1;
		while (l <= r) {
			ans = max(ans,max(v2[l], v2[r]));
			l = (l + 1) >> 1;
			r = (r - 1) >> 1;
		}
		cout << ans << "\n";
	}

	return 0;
}