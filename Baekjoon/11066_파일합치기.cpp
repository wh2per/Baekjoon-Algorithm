#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int bj_11066() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int ans = 0;
		int n;	
		cin >> n;
		vector<int> pages(n+1, 0);
		vector<int> sum(n + 1, 0);
		vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));

		for (int j = 1; j <= n; ++j) {
			cin >> pages[j];
			sum[j] = sum[j - 1] + pages[j];
		}
		
		for (int x = 1; x < n; ++x) {
			for (int y = 1; y + x <= n; ++y) {
				int m = x + y;
				d[y][m] = INT_MAX;

				for (int z = y; z < m; ++z)
					d[y][m] = min(d[y][m], d[y][z] + d[z + 1][m] + sum[m] - sum[y - 1]);
			}
		}
		
		cout << d[1][n] << "\n";
	}
	return 0;
}