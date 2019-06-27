#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int bj_2908() {
	string n1, n2;
	cin >> n1 >> n2;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	int a1 = stoi(n1);
	int a2 = stoi(n2);
	if (a1 > a2)
		cout << a1;
	else
		cout << a2;
	return 0;
}