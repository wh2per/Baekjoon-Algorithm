#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> d(1001, vector<int>(1001, 0));
	vector<char> result;

	for (int i = 1; i <= s1.length(); ++i) {
		for (int j = 1; j <= s2.length(); ++j) {
			if (s1[i - 1] == s2[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	cout << d[s1.length()][s2.length()]<<"\n";

	int i = s1.length();
	int j = s2.length();

	while (i >= 1 && j >= 1) {
		if (d[i][j] == d[i - 1][j]) {
			i--;
		}
		else if (d[i][j] == d[i][j - 1]) {
			j--;
		}
		else {
			result.push_back(s1[i - 1]);
			i--; 
			j--;
		}
	}

	for (i = result.size() - 1; i >= 0; --i)
		cout << result[i];

	return 0;
}