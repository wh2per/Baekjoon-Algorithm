#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cmp_word {
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second) {
			return true;
		}
		else if (p1.second > p2.second) {
			return false;
		}
		else {
			if (p1.first < p2.first)
				return true;
			else
				return false;
		}
	}
};

int bj_1181() {
	int n;
	cin >> n;
	vector<pair<string, int>> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m.push_back({s,s.length()});
	}

	sort(m.begin(), m.end(), cmp_word());
	string temp = "";
	for (auto a : m) {
		if(a.first!=temp)
			cout << a.first << '\n';
		temp = a.first;
	}
	return 0;
}