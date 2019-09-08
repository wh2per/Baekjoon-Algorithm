#include <iostream>
using namespace std;

/*
페르마 소정리 이용 a^(p-1) = 1(mod)p
a = n!, b = k!*(n-k)!
p = 10000000007
즉, (a/b)%p = a*b^(-1)%p
=> a * b^(-1) * 1 % p
=> a * b^(-1) * b^(p-1) % p
=> a * b^(p-2) % p
=> a%p * (b^(p-2) % p)%p
*/


int bj_11401() {
	long long ncr[4000001];
	int n, k;
	cin >> n >> k;
	ncr[0] = 1;
	ncr[1] = 1;

	// factorial 계산
	for (int i = 2; i <= n; ++i)
		ncr[i] = (ncr[i - 1] * i) % 1000000007;

	// a%p * (b^(p-2) % p)%p
	long long b = ncr[k] * ncr[n-k] % 1000000007;
	long long p = 1000000007 - 2;

	// b^(p-2)
	long long value = 1;
	while (p > 0) {
		if (p % 2) {
			value *= b;
			value %= 1000000007;
		}
		b = (b * b)% 1000000007;
		p /= 2;
	}

	cout << ((ncr[n] % 1000000007) * (value % 1000000007)) % 1000000007;
	return 0;
}