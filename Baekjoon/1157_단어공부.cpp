#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bj_1157() {
	vector<int> v(26, 0);
	string str;
	cin >> str;

	for (auto a : str)
		++v[tolower(a) - 'a'];

	int max = -1;
	bool flag = false;
	char ans = 'a';
	for (int i = 0; i < 26; ++i) {
		if (max < v[i]) {
			max = v[i];
			flag = false;
			ans = toupper(i + 'a');
		}
		else if (max == v[i])
			flag = true;
	}

	if (flag)
		cout << "?";
	else
		cout << ans;
	return 0;
}