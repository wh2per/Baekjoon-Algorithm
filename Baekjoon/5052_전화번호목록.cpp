#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int bj_5052() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<string> phone;
		for (int j = 0; j < n; ++j) {
			string s;
			cin >> s;
			phone.push_back(s);
		}
		
		sort(phone.begin(), phone.end());
		bool flag = true;
		for (int k = 1; k < phone.size(); ++k) {			// for문을 하나로 줄이는것이 핵심
			if (phone[k].find(phone[k - 1]) == 0) {
				cout << "NO" << '\n';
				flag = false;
				break;
			}
			if (!flag)
				break;
		}
		if (flag)
			cout << "YES" << '\n';
	}
	return 0;
}