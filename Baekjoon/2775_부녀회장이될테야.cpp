#include <iostream>
#include <vector>
using namespace std;

int bj_2775() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> k >> n;		// k층 n호
		vector<vector<int>> v(k+1, vector<int>(n + 1, 0));
		for (int i = 0; i < n + 1; ++i)
			v[0][i] = i;

		for (int i = 1; i < k + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				int temp = 0;
				for (int m = 1; m <= j; ++m)
					temp += v[i - 1][m];
				v[i][j] = temp;
			}
		}
		cout << v[k][n] << '\n';
	}
	return 0;
}