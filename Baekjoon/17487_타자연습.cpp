#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int space = 0;
	int left = 0;
	int right = 0;
	string a;
	getline(cin, a);

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == ' ')
			++space;
		else {
			if (isupper(a[i]))
				++space;
			char c = tolower(a[i]);
			if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'y' || c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' ||
				c == 'z' || c == 'x' || c == 'c' || c == 'v' || c == 'b') {
				++left;
			}
			else
				++right;
		}
	}

	if (left > right) {
		int diff = left - right;
		if (diff > space) {
			cout << left << " " << right + space;
		}
		else {
			space -= diff;
			right += diff;
			if (space % 2 == 0) {
				cout << left + space/2<< " " << right + space / 2;
			}
			else {
				cout << left + space / 2 + 1 << " " << right + space / 2;
			}
		}
	}
	else {
		int diff = right - left;
		if (diff > space) {
			cout << left + space << " " << right;
		}
		else {
			space -= diff;
			left += diff;
			if (space % 2 == 0) {
				cout << left + space / 2 << " " << right + space / 2;
			}
			else {
				cout << left + space / 2 + 1 << " " << right + space / 2;
			}
		}
	}
	return 0;
}