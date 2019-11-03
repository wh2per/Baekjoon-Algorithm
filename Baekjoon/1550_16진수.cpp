#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	string s;
	cin >> s;
	int a = 0;
	int cnt = 0;

	for (int i = s.length()-1; i >= 0; --i) {
		char c = s[i];

		if (c >= 'A') {
			a += (c - 'A' + 10)*pow(16,cnt);
		}
		else {
			a += (c - '0') * pow(16, cnt);
		}
		++cnt;
	}
	cout << a;
	return 0;
}