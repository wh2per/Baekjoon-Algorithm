#include <iostream>
using namespace std;

int bj_1330() {
	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << ">";
	else if (a < b)
		cout << "<";
	else
		cout << "==";
	return 0;
}