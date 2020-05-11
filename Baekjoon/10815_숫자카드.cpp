#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	cin >> m;
	while (m--) {
		int num;
		cin >> num;

		int low = 0, high = n - 1;
		int mid;
		bool flag = false;

		while (low <= high) {
			mid = (low + high) >> 1;
			if (v[mid] == num) {
				flag = true;
				break;
			}
			else if (v[mid] < num)
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (flag)
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
	return 0;
}