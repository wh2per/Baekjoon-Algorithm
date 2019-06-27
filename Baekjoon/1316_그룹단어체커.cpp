#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bj_1316() {
	int t;
	cin >> t;
	int ans = 0;

	while (t--) {
		string str;
		cin >> str;
		vector<bool> v(26, false);

		int prev = str[0] - 'a';
		int i = 0;
		for (i = 0; i < str.length(); ++i) {
			int temp = str[i] - 'a';
			if (prev != temp && v[temp])
				break;
			v[temp] = true;
			prev = temp;
		}

		if (i == str.length())
			++ans;
	}

	cout << ans;
	return 0;
}