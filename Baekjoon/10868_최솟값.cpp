#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int getIndex(int n) {			// 배열크기 정하기
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int size = getIndex(n);
	int start = size - n - 1;
	vector <int> v(size, 0);
	for (int i = size - n; i < size; ++i)
		cin >> v[i];

	int p = (size - 1) / 2;				// 구간합 구하기
	for (int i = p; i > 0; --i)
		v[i] = min(v[i * 2], v[i * 2 + 1]);

	for (int w = 0; w < m; ++w) {
		int a, b;
		cin >> a >> b;

		int L = a + start;
		int R = b + start;
		int ans = INT_MAX;

		while (L <= R) {
			ans = min(ans, min(v[L], v[R]));
			L = (L + 1) >> 1;
			R = (R - 1) >> 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
