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

	long long M = 0, Y = 0;

	while (t--) {
		int num;
		cin >> num;

		Y += (num / 30 + 1) * 10;
		M += (num / 60 + 1) * 15;
	}

	if (M > Y)
		cout << "Y " << Y;
	else if (M == Y)
		cout << "Y M " << Y;
	else
		cout << "M " << M;

	return 0;
}