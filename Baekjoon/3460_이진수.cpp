#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
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
		int num;
		cin >> num;

		string s="";

		while (num != 0) {
			if (num % 2 == 0)
				s = s + "0";
			else
				s = s + "1";
			num /= 2;
		}

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '1')
				cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}