#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long MOD = 1234567891;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	cin >> L;

	vector<long long> v(L+1,1);
	for (int i = 1; i <= L; ++i) 
		v[i] = v[i - 1] * 31 % MOD;

	long long ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < L; ++i) {
		long long num = s[i] - 'a' + 1;

		ans += v[i] * num % MOD;
	}

	cout << ans % MOD;

	return 0;
} 