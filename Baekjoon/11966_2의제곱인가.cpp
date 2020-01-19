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

	long long a;
	cin >> a;

	long long b = 1;
	bool flag = false;
	for (int i = 0; i <= 30; ++i) {
		if (a == b) {
			flag = true;
			break;
		}
		b *= 2;
	}

	if (flag)
		cout << 1;
	else
		cout << 0;
	return 0;
}