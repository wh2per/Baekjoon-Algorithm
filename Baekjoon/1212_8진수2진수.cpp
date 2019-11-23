#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	string s;
	cin >> s;
	
	if (s == "0"){
		cout << "0\n";
		return 0;
	}

	if (s[0] == '1')
		cout << 1;
	else if (s[0] == '2')
		cout << "10";
	else if (s[0] == '3') 
		cout << "11";
	else if (s[0] == '4') 
		cout << "100";
	else if (s[0] == '5') 
		cout << "101";
	else if (s[0] == '6') 
		cout << "110";
	else if (s[0] == '7') 
		cout << "111";

	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == '0')
			cout << "000";
		else if (s[i] == '1')
			cout << "001";
		else if (s[i] == '2')
			cout << "010";
		else if (s[i] == '3')
			cout << "011";
		else if (s[i] == '4')
			cout << "100";
		else if (s[i] == '5')
			cout << "101";
		else if (s[i] == '6')
			cout << "110";
		else if (s[i] == '7')
			cout << "111";
	}

	return 0;
}