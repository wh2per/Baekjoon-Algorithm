#include <iostream>
using namespace std;

int bj_2839() {
	int answer = 99999;
	int N;
	cin >> N;
	int start = 0;
	int end = N / 5;

	for (int i = start; i <= end; i++) {
		int ans = i;
		int left = N - (5 * i);
		if (left % 3 != 0 || left < 3) {
			if (left % 5 == 0) {
				ans += (left / 5);
				if (answer > ans)
					answer = ans;
			}
			continue;
		}
		else {
			ans += (left / 3);
			if (answer > ans)
				answer = ans;
		}
	}

	if (answer == 99999)
		cout << -1;
	else
		cout << answer;

	return 0;
}