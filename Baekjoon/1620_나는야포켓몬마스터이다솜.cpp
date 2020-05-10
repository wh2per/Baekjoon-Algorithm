#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> um;
	vector<string> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;

		v[i] = s;		// 번호별 정리
		um.insert({ s,i });
	}

	while (m--) {
		string s;
		cin >> s;

		if (s[0] >= '0' && s[0] <= '9') {		// 숫자일 경우
			int num = atoi(s.c_str());
			cout << v[num] << '\n';
		}
		else {
			cout << um[s] << '\n';
		}
	}

	return 0;
}