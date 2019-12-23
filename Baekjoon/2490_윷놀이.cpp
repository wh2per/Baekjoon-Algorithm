#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 3; ++i) {
		int num = 0;
		for (int j = 0; j < 4; ++j) {
			int c;
			cin >> c;
			if (c)
				++num;
		}
		if (num == 1)
			cout << "C\n";
		else if (num == 2)
			cout << "B\n";
		else if (num == 3)
			cout << "A\n";
		else if (num == 4)
			cout << "E\n";
		else
			cout << "D\n";
	}

	return 0;
}