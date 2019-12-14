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

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b + c >= 100)
		cout << "OK";
	else {
		int temp = min(a, min(b, c));
		if (temp == a)
			cout << "Soongsil";
		else if (temp == b)
			cout << "Korea";
		else
			cout << "Hanyang";
	}

	return 0;
}