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

	int t;
	cin >> t;
	while (t--) {
		int y = 0, g = 0;

		for (int i = 0; i < 9; ++i) {
			int a, b;
			cin >> a >> b;
			y += a;
			g += b;
		}

		if (y > g)
			cout << "Yonsei" << endl;
		else if (y == g)
			cout << "Draw" << endl;
		else
			cout << "Korea" << endl;
	}

	return 0;
}