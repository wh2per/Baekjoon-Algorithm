#include <iostream>
#include <vector>
using namespace std;

int ans_out = -1;

void bf_out(int day, int pay, vector<int>& d, vector<int>& p, int n) {
	if (day == n) {
		if (pay > ans_out)
			ans_out = pay;
		return;
	}

	if (day > n)
		return;

	bf_out(day + 1, pay, d,p,n);
	bf_out(day + d[day], pay + p[day], d, p, n);
}

int bj_14501(int day, int pay) {
	int N;
	cin >> N;
	vector<int> p(N);
	vector<int> t(N);
	
	for (int i = 0; i < N; ++i) {
		cin >> t[i];
		cin >> p[i];
	}

	bf_out(0, 0,t, p,N);

	cout << ans_out;
	return 0;
}