#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	for (int i = 0; i < x; i++) {
		for (int j = x - 1 - i; j > 0; j--) {
			cout << " ";
		}
		for (int k = 0; k <= i; k++)
			cout << "*";
		cout << '\n';
	}

	return 0;
}