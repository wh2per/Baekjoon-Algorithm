#include <iostream>
#include <vector>
using namespace std;

int bj_2003() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)	cin >> v[i];

	int start = 0, end = 0, ans = 0, sum;
	sum = v[0];

	while (n > start) {
		if (sum == m) {
			++ans;
			if (end + 1 >= n)
				break;
			sum -= v[start];
			++start;
			++end;
			sum += v[end];
		}
		else if (sum > m) {
			sum -= v[start];
			++start;
		}
		else {
			if (end + 1 >= n)
				break;
			++end;
			sum += v[end];
		}
	}
	cout << ans;
	
	return 0;
}