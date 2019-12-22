#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	long long num1 = 0, num2 = 0;
	for (int i = len1 - 1; i >= 0; --i) {
		if(s1[i]=='1')
			num1 += pow(2, len1 - i - 1);
	}

	for (int i = s2.length() - 1; i >= 0; --i) {
		if(s2[i] == '1')
			num2 += pow(2, len2 - i - 1);
	}

	long long num3 = num1 * num2;
	
	stack<int> s;
	while (num3 != 0) {
		s.push(num3 % 2);
		num3 /= 2;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}