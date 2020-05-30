#include <iostream>
using namespace std;

long long pow(int a, int b, int c) {
	if (b == 1)
		return a;
	long long t = pow(a, b / 2, c);
	if (b % 2 == 1)
		return ((t * t) % c * a) % c;
	else
		return (t * t) % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a % c, b, c);
	return 0;
}