#include <iostream>
#include <string>
using namespace std;

int bj_2941() {
	string s;
	cin >> s;
	s += "##";
	int ans=0;

	for (int i = 0; i < s.length()-2; ++i) {
		if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-'))
			i++;
		else if (s[i] == 'd') {
			if (s[i + 1] == '-')
				i++;
			else if (s[i + 1] == 'z' && s[i + 2] == '=')
				i += 2;
		}
		else if ((s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j')
			i++;
		else if ((s[i] == 's' || s[i] == 'z') && s[i + 1] == '=')
			i++;
		ans++;
	}
	cout << ans;
	return 0;
}