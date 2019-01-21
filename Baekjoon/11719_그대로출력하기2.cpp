#include <iostream>
#include <string>
using namespace std;

int bj_11719(void) {
	string n[100];

	for (int i = 0; i < 100; i++) {
		getline(cin, n[i]);
	}

	for (int i = 0; i < 100; i++) {
		cout << n[i] << '\n';
	}
	//system("pause");
	return 0;
}