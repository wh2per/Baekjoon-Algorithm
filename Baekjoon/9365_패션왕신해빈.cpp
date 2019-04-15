#include <iostream>
#include <map>
#include <string>
using namespace std;

int bj_9365() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		map<string, int> m;
		for (int j = 0; j < n; ++j) {
			string tmp,trash;
			cin >> trash >> tmp;
			if (m.count(tmp) > 0)
				m[tmp]++;
			else
				m.insert({ tmp,1 });
		}
		int ans = 1;
		for (auto a : m) 
			ans *= a.second + 1;
		cout << ans - 1 << '\n';
	}

	return 0;
}