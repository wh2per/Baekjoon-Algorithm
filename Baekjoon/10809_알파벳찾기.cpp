#include <iostream>
#include <string>
using namespace std;

int bj_10809() {
	string s;
	cin >> s;

	for (int i = 0; i < 26; i++) {
		int temp = s.find('a' + i);
		cout << temp << " ";
	}

	return 0;
}