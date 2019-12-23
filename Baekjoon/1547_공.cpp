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

	int pos = 1;
	int a, b;

	while (n--) {
		cin >> a >> b;
		if (a == pos || b == pos) {
			if (a == pos)
				pos = b;
			else
				pos = a;
		}
	}

	cout << pos;

	return 0;
}