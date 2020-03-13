#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	while (1) {
		string a, b;
		cin >> a >> b;

		if(a=="0" && b=="0")
			break;

		if (a.length() > b.length())
			swap(a, b);

		int ans = 0;
		bool carry = false;
		for (int i = 0; i < a.length(); ++i) {
			int c = a[a.length()-1-i]-'0' + b[b.length()-1-i]-'0';
			if (carry)
				++c;

			if (c > 9) {
				carry = true;
				++ans;
			}
			else
				carry = false;
		}

		for (int i = a.length(); i < b.length(); ++i) {
			if (carry) {
				if (b[b.length()-1-i] - '0' + 1 > 9)
					++ans;
				else
					carry = false;
			}
			else
				break;
		}

		cout << ans << endl;
	}

	return 0;
}