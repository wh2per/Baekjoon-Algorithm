#include <iostream>
#include <vector>
using namespace std;

long long inf_d[41][41];
long long inf_p, inf_q;

long long inf_dp(long long n, long long p, long long q) {
	if (n == 0)
		return 1;
	if (inf_d[p][q] != 0)
		return inf_d[p][q];
	return inf_d[p][q] = inf_dp(n / inf_p, p + 1, q) + inf_dp(n / inf_q, p, q + 1);
}

int bj_1351() {
	long long n;
	cin >> n >> inf_p >> inf_q;
	cout << inf_dp(n, 0, 0);
	return 0;
}