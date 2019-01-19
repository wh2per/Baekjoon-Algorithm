#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	for (int i = x; i > 0; i--) {
		for (int k = i; k > 0; k--)
			cout << "*";
		for (int j = x - i; j < 0; j++)
			cout << " ";
		cout << '\n';
	}
	return 0;
}