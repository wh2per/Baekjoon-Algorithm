#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string s;
		cin >> s;

		if (s == "0")
			break;

		int low = 0; 
		int high = s.length() - 1;
		bool flag = true;
		while (low < high) {
			if (s[low] != s[high]) {
				flag = false;
				break;
			}
			++low;
			--high;
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}