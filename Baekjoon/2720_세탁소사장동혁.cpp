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
		int n;
		cin >> n;

		cout << n / 25<<" ";
		n -= (n / 25)*25;

		cout << n / 10<<" ";
		n -= (n / 10)*10;

		cout << n / 5<<" ";
		n -= (n / 5)*5;

		cout << n << "\n";
	}

	return 0;
}