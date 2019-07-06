#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_2798() {
	int n, jack;
	cin >> n >> jack;
	vector<int> v(n,0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i != j && i != k && j != k) {
					int sum = v[i] + v[j] + v[k];
					if (sum<=jack && sum>ans)
						ans = sum;
				}
			}
		}
	}
	cout << ans;
	return 0;
}