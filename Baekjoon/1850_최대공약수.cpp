#include <iostream>
using namespace std;

int bj_1850() {
	// 1의 개수의 최대공약수가 결과 수의 1의 개수
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;

	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}

	for (int i = 0; i < a; ++i)
		cout << 1;
	
	return 0;
}