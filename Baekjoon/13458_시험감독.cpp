#include <iostream>
#include <vector>
using namespace std;

int bj_13458() {
	int N, B, C;
	long long ans = 0;
	cin >> N;
	vector<int> test(N);
	for (int i = 0; i < N; ++i) {
		cin >> test[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; ++i) {
		++ans;
		test[i] -= B;
		if (test[i] > 0) {
			if (test[i] >= C) {
				ans += test[i] / C;
				if (test[i] % C != 0)
					++ans;
			}
			else
				++ans;
		}
	}

	cout << ans;
	return 0;
}