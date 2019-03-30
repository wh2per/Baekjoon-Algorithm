#include <vector>
#include <string>
#include <iostream>
using namespace std;

int bj_10799() {
	string s;
	cin >> s;

	vector<int> v;
	int ans = 0;
	int t = 0;
	for (int i = 0; i < s.length() - 1; ++i) {
		if (s[i] == '(' && s[i + 1] == ')') {		// 레이저 일때
			for (int k=0; k<v.size(); ++k) 
				++v[k];
			++i;
		}
		else if (s[i]=='(') {			// 쇠막대기 시작
			v.push_back(0);
		}
		else {				// 쇠막대기 끝
			ans += v.back() + 1;
			v.pop_back();
		}
	}
	ans += v[0] + 1;
	cout << ans;
	return 0;
}