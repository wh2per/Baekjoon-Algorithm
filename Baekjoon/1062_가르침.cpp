#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int ans = 0;
	set<char> haveto;
	set<char> study;
	study.insert('a');
	study.insert('n');
	study.insert('t');
	study.insert('c');
	study.insert('i');

	int N, M;
	cin >> N >> M;
	
	vector<set<char>> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		s = s.substr(4, s.length()-8);
		set<char> us;
		for (int j = 0; j < s.length(); j++) {
			if (study.count(s[j]) == 0) { 		// 안 배운 단어
				us.insert(s[j]);
				haveto.insert(s[j]);
			}
		}
		v.push_back(us);			// 각 단어별로 배움이 필요한 글자를 들고있음
	}
	
	if (M < 5) {
		cout << 0;
		return 0;
	}

	if (M == 26) {
		cout << N;
		return 0;
	}

	int size = haveto.size();
	vector<char> temp;
	vector<int> check(size, 1);

	for (char c : haveto)
		temp.push_back(c);

	for (int i = 0; i < M - 5; i++)
		check[i] = 0;

	do {
		int tans = 0;
		set<char> s;		// 배운 단어
		for (int i = 0; i < size; i++) {
			if (check[i] == 0)
				s.insert(temp[i]);
		}

		for (int i = 0; i < v.size(); i++) {
			int cnt = 0;
			for (char c : v[i]) {
				if (s.count(c) != 0)		// 필요한 단어라면
					cnt++;
			}
			if (cnt == v[i].size())
				tans++;
		}
		if (tans > ans)
			ans = tans;
	} while (next_permutation(check.begin(), check.end()));

	cout << ans;
	
	return 0;
}