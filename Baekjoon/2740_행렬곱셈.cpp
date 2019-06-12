#include <iostream>
#include <vector>
using namespace std;

int bj_2740() {
	int m1, n1, m2, n2;
	cin >> m1 >> n1;
	vector<vector<int>> a(m1, vector<int>(n1, 0));
	for (int i = 0; i < m1; ++i) {
		for (int j = 0; j < n1; ++j)
			cin >> a[i][j];
	}
	cin >> m2 >> n2;
	vector<vector<int>> b(m2, vector<int>(n2, 0));
	for (int i = 0; i < m2; ++i) {
		for (int j = 0; j < n2; ++j)
			cin >> b[i][j];
	}

	for (int i = 0; i < m1; ++i) {
		for (int j = 0; j < n2; ++j) {
			int ans = 0;
			for (int k = 0; k < n1; ++k) {
				ans += a[i][k] * b[k][j];
			}
			cout << ans << " ";
		}
		cout << "\n";
	}

	return 0;
}