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
	int n, a, b, c=0;

	cin >> n;

	if (n == 2)
		cin >> a >> b;
	else
		cin >> a >> b >> c;

	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0 && c % i == 0)
			cout << i << endl;
	}

	return 0;
}