#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int bj_1062() {
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
		s = s.substr(4, s.length()-8);		// anta와 tica를 제외
		set<char> us;
		for (int j = 0; j < s.length(); j++) {
			if (study.count(s[j]) == 0) { 		// 안 배운 단어
				us.insert(s[j]);
				haveto.insert(s[j]);			// 모든 단어를 알려면 필요한 알파벳
			}
		}
		v.push_back(us);			// 각 단어별로 배움이 필요한 알파벳를 저장
	}
	
	if (M < 5) {		// a n t i c를 모르면 모든 단어를 모름
		cout << 0;
		return 0;
	}

	if (M == 26) {		// 알파벳전부 알면 모든 단어를 앎
		cout << N;
		return 0;
	}

	int size = haveto.size();	
	if (size > 0) {					// 알아야할 알파벳이 존재한다면?
		if (M - 5 == 0) {
			cout << 0;
			return 0;
		}

		if (M - 5 > size) {
			cout << N;
			return 0;
		}
		vector<char> temp;			
		vector<int> check(size, 1);		// {1,1,1,1,...} 

		for (char c : haveto)	// haveto를 vector로 변환
			temp.push_back(c);

		for (int i = 0; i < M - 5; i++)
			check[i] = 0;					// {0, 0, 1,1,1,1,...}
		
		do {
			int tans = 0;
			set<char> s;		// 배운 단어
			for (int i = 0; i < size; i++) {
				if (check[i] == 0)
					s.insert(temp[i]);
			}

			for (int i = 0; i < v.size(); i++) {		// 단어별 검사 
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
		} while (next_permutation(check.begin(), check.end()));		// 모든 경우 다 돌기

		cout << ans;
	}
	else				// 알아야할 알파벳이 없으면 존재하는 단어를 모두 앎
		cout << N;
	
	return 0;
}