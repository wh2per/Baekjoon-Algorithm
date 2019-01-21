#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_11721() {
	string x;
	getline(cin, x);

	int len = x.length();
	int index = 0;
	int temp = 0;

	for (int i = 0; i < len; i++) {
		index++;
		temp = x.length();
		if (index == 10 || (temp < 10 && i == len - 1)) {
			if (x.length() > 10) {
				cout << x.substr(0, 10) << '\n';
				x.erase(0, 10);
			}
			else {
				cout << x.substr(0, x.length());
			}
			index = 0;
		}
	}


	return 0;
}