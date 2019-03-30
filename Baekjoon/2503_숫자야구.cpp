#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int bj_2503() {
	int ans = 0;
	int N;
	cin >> N;
	map<string, pair<int, int>> m;
	for (int j = 0; j < N; ++j) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;
		m.insert({ num,{ strike,ball } });
	}

	for (int i = 123; i <= 987; ++i) {
		int count = 0;
		int f = i/100;
		int t = i%10;
		int s = (i % 100)/10;
		if (f == t || t == s || f == s || f < 1 || s < 1 || t < 1)
			continue;
		vector<int> c = { f,s,t };

		for (auto a : m) {
			vector<int> n(3);
			string num = a.first;
			for (int k = 0; k < 3; ++k)
				n[k] = num[k] - '0';

			int strike = 0;
			int ball = 0;
			// strike 검사
			for (int j = 0; j < 3; ++j){
				if (n[j] == c[j])
					++strike;
			}

			// ball 검사
			for (int j = 0; j < 3; ++j) {
				for (int b = 0; b < 3; ++b) {
					if (j != b && c[j]==n[b]) {
						++ball;
						break;
					}
				}
			}

			if (strike == a.second.first && ball == a.second.second)
				++count;
		}

		if (count == m.size())
			++ans;
	}
	cout << ans << '\n';
	return 0;
}