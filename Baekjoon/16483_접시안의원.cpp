#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	if ((n * n) % 4 > 1)
		cout << n * n / 4 + 1;
	else
		cout << n * n / 4;
	return 0;
}