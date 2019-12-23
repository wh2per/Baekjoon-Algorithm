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

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = n - i; j > 0; --j)
			cout << " ";
		for (int j = 0; j < i * 2 - 1; ++j)
			cout << "*";
		cout << endl;
	}

	return 0;
}