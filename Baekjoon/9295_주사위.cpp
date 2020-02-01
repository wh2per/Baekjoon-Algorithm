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
	for (int i = 1; i <= t; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		cout << "Case " << i << ": " << num1 + num2 << endl;
	}

	return 0;
}