#include <iostream>
#include <string>
using namespace std;

int bj_5622() {
	string str;
	cin >> str;
	int ans = 0;

	for (auto a : str) {
		int temp = a - 'A';
		if (temp > 17 && temp!=25)
			--temp;
		if (temp == 25)
			temp -= 2;
		temp /= 3;
		temp += 3;
		ans += temp;
	}
	cout << ans;
	return 0;
}