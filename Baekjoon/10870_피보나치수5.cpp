#include <iostream>
using namespace std;

int fibo5(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibo5(n - 2) + fibo5(n - 1);
}

int bj_10870() {
	int n;
	cin >> n;

	cout << fibo5(n);
	return 0;
}