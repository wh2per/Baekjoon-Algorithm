#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	string s;
	cin >> s;
	
	string result = s;
	for (int i = 1; i < n; i++){
		string temp;
		cin >> temp;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] != temp[j])
				result[j] = '?';
		}
	}

	cout << result << "\n";

	return 0;
}