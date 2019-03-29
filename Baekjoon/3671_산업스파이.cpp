#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool check_spy(int num) {
	int i;
	for (i = 2; i*i < num; ++i) {
		if (num%i == 0)
			return false;
	}
	if (i*i == num)
		return false;
	return true;
}

int bj_3671() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int ans=0;
		string s;
		cin >> s;
		vector<int> v;
		set<int> check;
		for (int j = 0; j < s.length(); ++j)
			v.push_back(s[j] - '0');

		sort(v.begin(), v.end());
		do {
			for (int p = 1; p <= v.size(); p++) {
				string tmp;
				bool flag = false;
				for (int k = 0; k < p; ++k) {
					if (!flag && v[k] != 0)
						flag = true;
					if (flag)
						tmp += to_string(v[k]);
				}
				int n = atoi(tmp.c_str());
				if (check.count(n) == 0 && n > 1 && check_spy(n)) {
					check.insert(n);
					ans++;
				}
			}
		} while (next_permutation(v.begin(), v.end()));
		cout << ans << '\n';
	}
	return 0;
}