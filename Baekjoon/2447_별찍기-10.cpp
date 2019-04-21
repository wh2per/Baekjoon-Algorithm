#include <iostream>
#include <vector>
#include <string>
using namespace std;

int bj_2447() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v = { "***", "* *", "***" };
	int n;
	cin >> n;
	if (n > 1) {
		int k = 3;
		while (k<n) {
			vector<string> temp(v.begin(), v.end());		// 이전 배열 값 복사

			// 2번 반복
			for (int j = 0; j < 2; ++j) {
				for (int i = 0; i < temp.size(); ++i)
					v[i] += temp[i];
			}
			
			// 1번 + 비우기 + 1번
			for (int j = 0; j < temp.size(); ++j) {
				string t = temp[j];
				for (int i = 0; i < temp[j].length(); ++i)
					t += " ";
				t += temp[j];
				v.push_back(t);
			}

			// 3번 반복
			for (int j = 0; j < temp.size(); ++j) {
				string t = "";
				for (int i = 0; i < 3; ++i)
					t += temp[j];
				v.push_back(t);
			}
			k *= 3;
		}
	}
	else {
		v.clear();
		v.push_back("*");
	}

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';

	return 0; 
}
