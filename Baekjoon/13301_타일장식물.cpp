#include <string>
#include <vector>
#include <iostream>
using namespace std;

int bj_13301() {
	int N;
	cin >> N;
	long long d[81];
	long long s[81];
	d[0] = 0;
	d[1] = 1;
	s[1] = 4 * d[1];
	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + d[i - 2];
		s[i] = s[i - 1] - d[i] + d[i] * 3;
	}
	cout << s[N];

	return 0;
}