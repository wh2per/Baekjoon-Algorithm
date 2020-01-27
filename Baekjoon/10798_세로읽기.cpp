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

	vector<string> s(5, "");

	for (int i = 0; i < 5; ++i)
		cin >> s[i];

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i < s[j].length())
				cout << s[j][i];
		}
	}

	return 0;
}