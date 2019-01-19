#include <iostream>

using namespace std;

int bj_2441(void) {
	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int k = 0; k < n - i; k++)
			cout << " ";

		for (int j = i; j > 0; j--) {
			cout << "*";
		}
		cout << '\n';
	}

	//system("pause");
	return 0;
}
