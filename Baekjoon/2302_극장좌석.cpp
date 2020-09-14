#include <iostream>
using namespace std;

int fb[42];

int main() {
	fb[0] = 1;
	fb[1] = 1;

	for (int i = 2; i < 42; ++i)
		fb[i] = fb[i - 1] + fb[i - 2];

	int n, m;
	cin >> n >> m;

	if (m == 0)
		cout << fb[n];
	else {
		int temp = 0;

		int ans = 1;
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;

			ans *= fb[num - temp - 1];
			temp = num;
		}

		ans *= fb[n - temp];
		cout << ans;
	}

	return 0;
}