#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	for (int i = n-1; i >= 0; --i)
		cin >> left[i];
	for (int i = n - 1; i >= 0; --i)
		cin >> right[i];

	vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));	

	for (int i = 0; i <= n; i++)
		d[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]);
			if (d[i][j - 1] != -1 && left[i - 1] > right[j - 1])
				d[i][j] = d[i][j - 1] + right[j - 1];
		}
	}

	cout << d[n][n];
	return 0;
}