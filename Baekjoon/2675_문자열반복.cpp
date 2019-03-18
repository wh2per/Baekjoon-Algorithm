#include <iostream>
#include <string>
using namespace std;

int bj_2675() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int R;
		cin >> R;
		string s;
		cin >> s;

		string ans="";
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < R; k++)
				ans += s[j];
		}
		cout << ans << endl;
	}
	
	return 0;
}