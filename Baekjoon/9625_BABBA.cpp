#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a = 1;
	int b = 0;

	while (n-- > 0) {
		int tempB = a;
		a -= a;
		a += b;
		b += tempB;
	}

	cout << a << " " << b;

	return 0;
}