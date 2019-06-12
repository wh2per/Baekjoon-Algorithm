#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_15483() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> d(1001, vector<int>(1001, 0));
	int len1 = s1.length();
	int len2 = s2.length();
	
	for (int i = 0; i <= len1; ++i)
		d[i][0] = i;

	for (int i = 0; i <= len2; ++i)
		d[0][i] = i;
	
	for (int i = 1; i <= len1; i++) { 
		for (int j = 1; j <= len2; j++) { 
			if (s1[i - 1] == s2[j - 1]) 
				d[i][j] = d[i - 1][j - 1]; 
			else 
				d[i][j] = min(d[i - 1][j - 1] + 1, min(d[i][j - 1] + 1, d[i - 1][j] + 1));
		} 
	}

	cout << d[len1][len2];
	return 0;
}