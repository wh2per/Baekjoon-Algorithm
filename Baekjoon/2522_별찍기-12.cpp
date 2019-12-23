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
		for (int j = 0; j < n - i; ++j)
			cout << " ";
		for (int j = 0; j < i; ++j)
			cout << "*";
		cout << endl;
	}

	for (int i = n-1; i > 0; --i) {
		for (int j = 0; j < n - i; ++j)
			cout << " ";
		for (int j = 0; j < i; ++j)
			cout << "*";
		cout << endl;
	}

	return 0;
}