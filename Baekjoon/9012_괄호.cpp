#include<string>
#include <iostream>

using namespace std;

int bj_9012() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		string s;
		cin >> s;

		int l = 0;
		int r = 0;

		if (s[0] == ')') {		// ) 로 시작하면 탈락
			cout << "NO" << '\n';
			continue;
		}

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')			// (와 )의 갯수 파악
				l++;
			else
				r++;
			if (r > l) 
				break;
		}
		if (l != r) {			// 갯수가 안맞아도 탈락
			cout << "NO" << '\n';
			continue;
		}
		else {
			cout << "YES" << '\n';
			continue;
		}
	}

	return 0;
}